#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;


map<string, double> table;
//计算器包含4个部分：分析器、输入函数、符号表和驱动
enum class Kind :char {
	name, number, end,
	plus = '+', minus = '-', mul = '*', div = '/',
	print = ';', assign = '=', lp = '(', rp = ')'
};
struct Token {
	Kind kind;
	string string_value;
	double number_value;
};//Token 是一个形如{单词类型，值}的对
class Token_stream
{
public:
	Token_stream(istream& s) :ip{ &s }, owns{ false } {}
	Token_stream(istream* p) :ip{ p }, owns{ true } {}

	Token_stream() { close(); }

	Token get();//读取并返回下一个单词
	Token& current();//刚刚读入的单词

	void set_input(istream& s) { close(); ip = &s; owns = false; }
	void set_input(istream* p) { close(); ip = p; owns = true; }
private:
	void close() { if (owns) delete ip; }

	istream* ip;//指向输入流的指针
	bool owns;//Token_stream 有流吗，用于指示输入流所有权的布尔值
	Token ct{ Kind::end };//当前单词
};

Token_stream ts{cin};//使用cin中的输入数据

double term(bool get);
//每个分析函数接受一个名为get的bool类型实参，它指明函数是否需要调用Token_stream::get()以获取下一个单词

double expr(bool get);//处理加法和减法


//在对某个名字执行具体操作之前，计算器首先向前查看改名字是否被赋值或者只是从中读取了内容
//两种情况下都要用到符号表，符号表的类型是map

double prim(bool get);

int no_of_errors;

double error(const string& s);

void calculate();

int main(int argc,char *argv[])
{
	switch (argc)
	{
	case 1:
		break;
	case 2://从实参字符串读取数据
		ts.set_input(new istringstream{ argv[1] });
		break;
	default:
		error("too many arguments");
		break;
	}

	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;
	calculate();
	return no_of_errors;
}





double expr(bool get)
{
	double left = term(get);

	for (;;) {
		switch (ts.current().kind) {
		case Kind::plus:
			left += term(true);
			break;
		case Kind::minus:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}


double term(bool get)
{
	double left = prim(get);
	for (;;) {
		switch (ts.current().kind)
		{
		case Kind::mul:
			left *= prim(true);
			break;
		case Kind::div:
			if (auto d = prim(true))
			{
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
}

double prim(bool get)
{
	if (get) ts.get();
	switch (ts.current().kind)
	{
	case Kind::number://浮点数常量
	{
		double v = ts.current().number_value;
		ts.get();
		return v;
	}
	case Kind::name:
	{
		double& v = table[ts.current().string_value];//找到对应的项
		if (ts.get().kind == Kind::assign) v = expr(true);//看到了'='：赋值运算
		return v;
	}
	case Kind::minus://一元减法
		return -prim(true);
	case Kind::lp:
	{
		auto e = expr(true);
		if (ts.current().kind != Kind::rp) return error("')' expected");
		ts.get();//吃掉了')'
		return e;
	}
	default:
		return error("primary expected");
	}
}

double error(const string & s)
{
	no_of_errors++;
	cerr << "error:" << s << endl;
	return 1;
}

void calculate()
{
	for (;;) {
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
	}
}

Token Token_stream::get()
{
	char ch = 0;
	//*ip >> ch;
	do {
		if (!ip->get(ch)) return ct = { Kind::end };
	} while (ch != '\n' && isspace(ch));
	switch (ch)
	{
	case 0://ch==0代表输入过程结束
		return ct = { Kind::end };//{Kind::end}等价于{Kind::end,0,0}
	//表达式终止符;括号和运算符的处理方式->直接返回它们的值
	case ';':
	case '\n':
		return ct = { Kind::print };
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
		return ct = { static_cast<Kind>(ch) };//char和Kind之间没有隐式类型转换规则，所以必须使用static_cast
	//数字的处理方式：
	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
	case '.':
		ip->putback(ch);//把第一个数字（或者.）放回到输入流中
		*ip >> ct.number_value;//把数字放入ct
		ct.kind = Kind::number;
		return ct;
	default://名字,名字=,或者错误
		if (isalpha(ch)) {
			ct.string_value = ch;
			while (ip->get(ch) && isalnum(ch))
				ct.string_value += ch;
			ip->putback(ch);
			return ct = {Kind::name};
		}
		error("bad token");
		return ct = { Kind::print };
	}
	
}

Token & Token_stream::current()
{
	return ct;
}
