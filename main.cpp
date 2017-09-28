#include <iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<unordered_map>
#include<sstream>
#include<chrono>
#include<map>

int yylex();
extern int yyval;
extern FILE* yyin;
extern char* yytext;

class upsidedown{
	//std::string filename;
	std::stringstream is;
	std::map<char, std::string> db;
public:
	void play(); //Triggers the upside down conversion by callying transform_stdin or transform_file
	upsidedown();
	void init_db();
	void print_string_upsidedown( std::string& );
	void process_stdin( );
	void process_file( );
	
	//Delete the ctors that are not needed
	//upsidedown(const upsidedown&) = delete;
	//upsidedown& operator=( const upsidedown& ) = delete;
};

upsidedown::upsidedown(): is(), db(){		init_db();		}

void upsidedown::play(){
	if( yyin == stdin ){
		process_stdin();
	}
	else process_file();
}

void upsidedown::init_db(){
		//Insert Lower case letters to map
	db['a'] = "\u0250";	db['b'] = "\u0071";	db['c'] = "\u0254";	db['d'] = "\u0070";	db['e'] = "\u01DD";	db['f'] = "\u025F";	db['g'] = "\u0253";	db['h'] = "\u0265";	db['i'] = "\u0131";	db['j'] = "\u027E";	db['k'] = "\u029E";	db['l'] = "\u006C";	db['m'] = "\u026F";	db['n'] = "\u0075";	db['o'] = "\u006F";	db['p'] = "\u0064";	db['q'] = "\u0062";	db['r'] = "\u0279";	db['s'] = "\u0073";	db['t'] = "\u0287";	db['u'] = "\u006E";	db['v'] = "\u028C";	db['w'] = "\u028D";	db['x'] = "\u0078";	db['y'] = "\u028E";	db['z'] = "\u007A";
	
	//Insert upperccase letters to map
	db['A'] = "\u0250";	db['B'] = "\u0071";	db['C'] = "\u0254";	db['D'] = "\u0070";	db['E'] = "\u01DD";	db['F'] = "\u025F";	db['G'] = "\u0253";	db['H'] = "\u0265";	db['I'] = "\u0131";	db['J'] = "\u027E";	db['K'] = "\u029E";	db['L'] = "\u006C";	db['M'] = "\u026F";	db['N'] = "\u0075";	db['O'] = "\u006F";	db['P'] = "\u0064";	db['Q'] = "\u0062";	db['R'] = "\u0279";	db['S'] = "\u0073";	db['T'] = "\u0287";	db['U'] = "\u006E";	db['V'] = "\u028C";	db['W'] = "\u028D";	db['X'] = "\u0078";	db['Y'] = "\u028E";	db['Z'] = "\u007A";
	
	//Insert digits to map
	db['0'] = '0';	db['1'] = "\u0196";	db['2'] = "\u1105";	db['3'] = "\u0190";	db['4'] = "\u3123";	db['5'] = "\u03DB";	db['6'] = '9';	db['7'] = "\u3125";	db['8'] = '8';	db['9'] = '6';	
	
	//Insert special characters to map
	db[','] = "\'";	db['.'] = "\u02D9";	db['\?'] = "\u00BF";	db['!'] = "\u00A1";	db['\"'] = ",,";	db['\''] = ',';	db['`'] = ',';	db['('] = ')';	db[')'] = '(';	db['<'] = '>';	db['>'] = '<';	db['['] = ']';	db[']'] = '[';	db['{'] = '}';	db['}'] = '{';	db['&'] = "\u214B";	db['_'] = "\u203E";		
	db[' '] = ' ';	db['\n'] = "\n";
}

void print_string_upsidedown(std::string& str ){
	std::map<char, std::string> db;
	
	//Insert Lower case letters to map
	db['a'] = "\u0250";	db['b'] = "\u0071";	db['c'] = "\u0254";	db['d'] = "\u0070";	db['e'] = "\u01DD";	db['f'] = "\u025F";	db['g'] = "\u0253";	db['h'] = "\u0265";	db['i'] = "\u0131";	db['j'] = "\u027E";	db['k'] = "\u029E";	db['l'] = "\u006C";	db['m'] = "\u026F";	db['n'] = "\u0075";	db['o'] = "\u006F";	db['p'] = "\u0064";	db['q'] = "\u0062";	db['r'] = "\u0279";	db['s'] = "\u0073";	db['t'] = "\u0287";	db['u'] = "\u006E";	db['v'] = "\u028C";	db['w'] = "\u028D";	db['x'] = "\u0078";	db['y'] = "\u028E";	db['z'] = "\u007A";
	
	//Insert upperccase letters to map
		db['A'] = "\u0250";	db['B'] = "\u0071";	db['C'] = "\u0254";	db['D'] = "\u0070";	db['E'] = "\u01DD";	db['F'] = "\u025F";	db['G'] = "\u0253";	db['H'] = "\u0265";	db['I'] = "\u0131";	db['J'] = "\u027E";	db['K'] = "\u029E";	db['L'] = "\u006C";	db['M'] = "\u026F";	db['N'] = "\u0075";	db['O'] = "\u006F";	db['P'] = "\u0064";	db['Q'] = "\u0062";	db['R'] = "\u0279";	db['S'] = "\u0073";	db['T'] = "\u0287";	db['U'] = "\u006E";	db['V'] = "\u028C";	db['W'] = "\u028D";	db['X'] = "\u0078";	db['Y'] = "\u028E";	db['Z'] = "\u007A";
	
	//Insert digits to map
	db['0'] = '0';	db['1'] = "\u0196";	db['2'] = "\u1105";	db['3'] = "\u0190";	db['4'] = "\u3123";	db['5'] = "\u03DB";	db['6'] = '9';	db['7'] = "\u3125";	db['8'] = '8';	db['9'] = '6';	
	
	//Insert special characters to map
	db[','] = "\'";	db['.'] = "\u02D9";	db['\?'] = "\u00BF";	db['!'] = "\u00A1";	db['\"'] = ",,";	db['\''] = ',';	db['`'] = ',';	db['('] = ')';	db[')'] = '(';	db['<'] = '>';	db['>'] = '<';	db['['] = ']';	db[']'] = '[';	db['{'] = '}';	db['}'] = '{';	db['&'] = "\u214B";	db['_'] = "\u203E";		
	db[' '] = ' ';	db['\n'] = "\n";
	std::string rev = "";
	for(unsigned i = 0; i < str.length(); i++ ){
		rev+=db[str[i]];
	}
	std::cout << rev << std::endl;
}

void upsidedown::print_string_upsidedown(std::string& str ){
	std::string rev = "";
	for(unsigned i = 0; i < str.length(); i++ ){
		rev+=db[str[i]];
	}
	std::cout << rev << std::endl;
}

void upsidedown::process_file(){
	std::string str = "";
	int token =  yylex();
	while( token ){
		  str+=((char)token);
		 token = yylex(); 
	}	
			std::reverse(str.begin(), str.end());
			print_string_upsidedown(str);
}


void upsidedown::process_stdin(){
	std::string str = "";
	int token =  yylex();
	while( token ){
		//Read until users enters a new line which means we end our read of tokens and output the reverse upsidedown result  
		if( token != 10 ){
			str+=((char)token);	
		}
		if( token == 10 ){
			std::reverse(str.begin(), str.end());
			print_string_upsidedown(str);
			str = "";
		}
		 token = yylex(); 
	}	
}




int main( int argc, char** argv){

	upsidedown n;
auto start = std::chrono::system_clock::now();
	if( argc == 2 ){
		if( !(yyin = fopen(argv[1], "r")) ){
			std::cerr << "couldn't open the file" << std::endl;
			exit(1);
		}
	}
	else	yyin = stdin;
	n.play();
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> diff = end - start;
std::cout << diff.count() << std::endl;
  std::cout << "Translation complete" << std::endl;
  return 0;
}
