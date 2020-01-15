
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <string.h>
#include <vector>
#include <sstream>
#define N 50
#define OP 5
using namespace std;

// readfile
void readFile();
void exeFile(string str, bool assem);
void skipSpace(string file,int *i);
// get string
string WFgt(string str, int *i);          // while, for
string IFgt(string str, int *i);          // if
string copyContent(string file,int *i);
string copyContent_semi(string file,int *i);
string copyBoolean(string file,int *i);
// compute
void other(string str,int assem);
void updateValue(string str,int assem);
// inorder to postorder and calculate function
int calculate(vector<string> postorder);
vector<string> to_postorder(char inorder[], char postorder[]);
int priority(char c);
char top_data();
void clearblank( char inorder[]);
bool IsFull();
bool IsEmpty(void);
int pop();
void push(char item);
int compute_int(string str);
void declare_variable(string key, int value);
/////////////////////////////////////////////////////////////////
char op[OP] = {'(','+','-','*','/'};
int op_priority[OP] = {0,1,1,2,2};
int priority(char c);
vector<string> to_postorder(char inorder[], char postorder[]);
void clearblank(char inorder[]);
char stack[N]; // This is a global variable.
int top=-1;
////////////////////////////////////////////////////////////////
// for ifElse while
void for_func(string boolean, string content, bool assem,int lcount);
void ifElse( string boolean ,string content ,int e, bool assem,int Count,int index);
void ifwhile( string boolean ,string content, bool assem,int wcount);
// bool
bool computebool (string boolean,int assem);
// int
void int_func(string str, bool assem);
bool is_variable_declare(string str);
int call_variable(string key);
// printf
void printf_func(string str, bool assem);
////////////////////////////////////////////////////////////////
// assembly
void assembly_if(string boolean,string content,int Count,int index,bool next);
void assembly_for(string declare, string boolean, string compute, string content ,int lcount);
void assembly_while(string boolean, string content, int wcount);
void assembly_int(string key, int value);
void assembly_printf_str(string content);
void assembly_printf_int(string content);
void assembly_computebool_one(string A );
void assembly_computebool_two(string A , int state , string B );
void assembly_updatevalue(string A , int state , string B );
string int_to_string(int value);
bool is_error=false;
int index_count = 0;
int loop_count = -1;
int while_count = -1;
string toasm = "\n.code\nmain PROC\n";

map<string,int> variable;

int main (){
	readFile();
	system("Pause");
	return 0;
}

void readFile(){
	fstream fin;
	fin.open("Source.txt",ios::in);

	char ch;
	string file;
	if(!fin){
		cout<<"file error"<<endl;
		is_error=1;
	}
	else{
		while(fin.get(ch)) file+=ch;
	}
	exeFile(file,0);
	cout << "-------------" << endl;
	if(is_error==0) {
		exeFile(file,1);
		toasm.insert(0,"temp2 DWORD 0\n").insert(0,"temp DWORD 0\n");
		toasm.insert(0,".data\n");
		toasm.insert(0,"INCLUDE Irvine32.inc\n");
		toasm.append("call Crlf\ncall WaitMsg\n");
		toasm.append("main ENDP\nEND main\n");
		cout << toasm;
		fstream fout;
		fout.open("Source.asm",ios::out);
		fout<<toasm;
	}
	return;
}

void exeFile(string str, bool assem){
	string input="";
	string boolean="";
	int i=0;
	skipSpace(str,&i);
	for( i=0; i<str.length();){
		skipSpace(str,&i);
		input="";
		if(str[i]=='{'){i++;}
		while((str[i]!='\n')&&(str[i]!='}')&&( str[i]!=' ')&&( str[i]!='\t' )&&( int(str[i])!=0 )&&( str[i]!='(') &&( i+1<str.length())) {
			input+=str[i];
			i++;
		}
		if(input=="int"){
			input=copyContent_semi(str,&i);
			int_func(input,assem);
			input="";
		}else if(input=="printf"){
			input=copyContent_semi(str,&i);
			printf_func(input,assem);
			input="";
		}else if(input=="if"){
			skipSpace(str,&i);
		    boolean=copyBoolean(str,&i);
		    input=IFgt(str,&i);
		    if(assem)index_count++;
		    ifElse(boolean,input,0,assem,0,index_count);
		    input="";
		}else if(input=="for"){
            boolean=copyBoolean(str,&i);
			input=WFgt(str,&i);
			if(assem)loop_count++;
			for_func(boolean,input,assem,loop_count);
			input="";
		}else if(input=="while"){
			boolean=copyBoolean(str,&i);
			input=WFgt(str,&i);
			if(assem)while_count++;
			ifwhile(boolean,input,assem,while_count);
			input="";
		}else if(input=="else"){
			WFgt(str,&i);
			cout<<"error!!  there is no IF  "<<endl;
			is_error=1;
			input="";
		}else if(input==""){
			return;
		}else{
		    i=i-input.length();
		    input=copyContent_semi(str,&i);
			other(input,assem);
			input="";
		}
	}
	return;
}

/*
func: find the char after space
*/
void skipSpace (string file, int *i){
	while(file[*i]==' '||file[*i]=='\t'||file[*i]=='\n' || int(file[*i])==0)
    {
    	(*i)++;
    }
    return;
}

/*
func: compute, updatevalue
*/
void other(string str,int assem){



	int i=0;
	skipSpace(str,&i);
	string d="";
	while(str[i]=='{'||str[i]=='}'||str[i]==';'){i++;}
	if(i>=str.length()){return;}

	if ((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)){
		while(str[i]!=0&&str[i]!='\t'&&str[i]!='\n'&&str[i]!=' '&&str[i]!='='&&str[i]!='-'&&str[i]!='+'&&str[i]!='*'&&str[i]!='/'&&str[i]!=';'){
		    d+=str[i];
		    (i)++;
		}

		if(is_variable_declare(d)){
			updateValue(str,assem);
			return;
		}else{
			cout<<"error! "<<endl;
			is_error=1;
			return;
		}

	}
	return;
}

// update value
void updateValue(string str , int assem){
	string d="";
	string compute="";
	string value="";
	int state=0;
	int i=0;
	// 0 =
	// 1 -=
	// 2 +=
	// 3 --
	// 4 ++
	// 5 *=
	// 6 /=

	skipSpace(str,&i);

	while(str[i]!=' '&&str[i]!='='&&str[i]!='-'&&str[i]!='+'&&str[i]!='*'&&str[i]!='/'&&str[i]!=';'){
	    d+=str[i];
	    (i)++;
	}
	skipSpace(str,&i);

	if(str[i]=='='){ // =
	    state=0;
	    i++;
	}else if (str[i]=='-'){
	    i++;
	    if(str[i]=='='){ // -=
	        state=1;
	        i++;
	    }else if(str[i]=='-'){ // --
	        state=3;
	        i++;
	    }else { //
	        state=-1;
	        cout<<"error"<<endl;
	        is_error=1;
	    }
	}else if (str[i]=='+'){
	    (i)++;
	    if(str[i]=='='){ // +=
	        state=2;
	        (i)++;
	    }
	    else if(str[i]=='+'){ // ++
	        state=4;
	        (i)++;
	    }else{ //
	        state=-1;
	        cout<<"error"<<endl;
	        is_error=1;
	    }
	}else if (str[i]=='*'){
	    (i)++;
	    if(str[i]=='='){ // +=
	        state=5;
	        (i)++;
	    }else { //
	        state=-1;
	        cout<<"error"<<endl;
	        is_error=1;
	    }
	}else if (str[i]=='/'){
	    (i)++;
	    if(str[i]=='='){ // +=
	        state=6;
	        (i)++;
	    }else { //
	        state=-1;
	        cout<<"error"<<endl;
	        is_error=1;
	    }
	}else{
        state=-1;
        cout<<"error"<<endl;
        is_error=1;
	}
	skipSpace(str,&i);

	if(state!=3&&state!=4&&((str[i]>=48&&str[i]<=57)||(str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)||str[i]=='(')){
	    while((str[i]!=0&&(str[i]!=';'))){
			value+=str[i];
			(i)++;
		}
		(i)++;
	}

	// 0 =
	// 1 -=
	// 2 +=
	// 3 --
	// 4 ++
	// 5 *=
	// 6 /=

	//======== assem=0  =================//
	if(assem==0){
		if(is_variable_declare(d)){
			switch(state){
			    case 0:
			    	variable[d]=compute_int(value);
			        break;
			    case 1:
			        variable[d]-=compute_int(value);
			        break;
			    case 2:
			        variable[d]+=compute_int(value);
			        break;
			    case 3:
			        variable[d]--;
					break;
			    case 4:
			        variable[d]++;
			        break;
			    case 5:
			        variable[d]*=compute_int(value);
			        break;
			    case 6:
			        variable[d]/=compute_int(value);
			        break;
			    case -1:
			        cout<<"error!"<<endl;
			        is_error=1;
			        return;
			}
		}else{
			cout<< d <<" the_variable_is_not_declare"<<endl;
			is_error=1;
			return;
		}
	}
	else{
        assembly_updatevalue(d ,state,value);
        return;
	}

	return;
}

// for
void for_func(string boolean, string content, bool assem,int lcount){
	bool check_1=0, check_2=0;
    string str_1="", str_2="", str_3="";

	for(int x=1; x<boolean.length(); x++){
		if(check_1==0){
			str_1+=boolean[x];
			if(boolean[x]==';'){
				if(assem==0) exeFile(str_1,assem);
				check_1=1;
			}
		}else if(check_2==0){
			if(boolean[x]==';'){
			check_2=1;
			}else{
			str_2+=boolean[x];
			}
		}else{
			if(boolean[x]==')') str_3+=';';
			else str_3+=boolean[x];
		}
	}

	int i=0;
    if(content[i]=='{') content=copyContent(content,&i);

	if(assem==1){
		assembly_for(str_1,str_2,str_3,content,lcount);
	}
	if(assem==0){
		while(computebool(str_2,assem)){
			exeFile(content,assem);
			exeFile(str_3,assem);
		}
	}
	return;
}

// if-else
void ifElse( string boolean ,string content ,int e, bool assem,int Count,int index){
	int i=0;
	int exe=e;

	string ifcontent="";
	string input="";
	skipSpace(content,&i);

    if(content[i]=='{'){
        ifcontent=copyContent(content,&i);
    }else{
	    if(computebool(boolean,0)){
	        ifcontent=WFgt(content,&i);
	    }else{
			ifcontent=IFgt(content,&i);
		}
    }
    ///////////////////
    //if(assem==1) assembly_if(boolean, ifcontent,++Count,index,0);
	////////////////////
	if(assem==0){
		if(computebool(boolean,assem)){
			if(exe==0 && (assem==0 || assem==2)){
	        	exeFile(ifcontent,assem);
		        exe=1;
			}
	    }
	}
	i=0;
    int leftcnt=0;
    int rightcnt=0;
	while(i<content.length()){
		if(content[i]=='{') {
			leftcnt++;
			i++;
		}
		else if(content[i]=='}'){
			rightcnt++;
			i++;
		}
	    else if(content[i]=='e'&&content[i+1]=='l'&&content[i+2]=='s'&&content[i+3]=='e'&&leftcnt==rightcnt){
			i=i+4;
			skipSpace(content,&i);

	    	if((content[i-1]==' '||content[i-1]=='\t'||content[i-1]=='\n')&&content[i]=='i'&&content[i+1]=='f'){
	    		if(assem==1) assembly_if(boolean, ifcontent,++Count,index,0);
				i=i+2;
				skipSpace(content,&i);
				boolean=copyBoolean(content,&i);

				while(i<content.length()){
	                input+=content[i];
	            	i++;
	            }
		        ifElse(boolean,input,exe,assem,Count,index);
		        return;
	    	}else {
	    		if(assem==1) assembly_if(boolean, ifcontent,++Count,index,0);
				input="";

				skipSpace(content,&i);
				if(content[i]=='{') input=copyContent(content,&i);
				else{
					while(content[i]=='}'||content[i]==';'){i++;}
					skipSpace(content,&i);

					while(i<content.length()){
					    input+=content[i];
						i++;
	        		}
				}
        		/////////////////////////////////
        		if(assem==1) assembly_if("", input,++Count,index,1);
        		/////////////////////////////////
				if(exe==0 && assem==0){
					exeFile(input,assem);
				}
				return;
    		}
    	}
    	else i++;
    }
    if(assem==1)assembly_if(boolean, ifcontent,++Count,index,1);
	return;
}

//while( ){}
void ifwhile(string boolean ,string content, bool assem, int wcount ){
	int i=0;
	skipSpace(content,&i);

    if(content[i]=='{') content=copyContent(content,&i);
	if(assem==0){
			while(computebool(boolean,assem))
		    {
				exeFile(content,assem);  //執行 while 的功能
		    }
	}
	if(assem==1){
		assembly_while(boolean,content,wcount);
	}
}

string WFgt(string str, int *i){
	string input="";
	int cont=0;
	skipSpace(str,i);
	if(str[*i]=='{'){
		cont++;
		input+=str[*i];
		(*i)++;
		while( cont ){
			if(str[*i]=='{'){ cont++;  }
			if(str[*i]=='}'){
			    cont--;
			    if( cont==0){ input+=str[*i];
			    (*i)++; break;}
			}
			input+=str[*i];
			(*i)++;
		}

            return input;
	}else{
        input="";
        while(str[*i]!=';' && int(str[*i])!=0&& *i<str.length()){
			input+=str[(*i)++];

			if(input=="for" || input=="while"){
				input+=copyBoolean(str,i);
				skipSpace(str,i);
				input+= WFgt(str,i);
				return input;
			}else if(input=="if"){
		        input+=copyBoolean(str,i);
		        skipSpace(str,i);
		        input+= IFgt(str,i);
			    return input;
			}
		}
		if( int(str[*i])!=0&& *i<str.length())
	    {
	        if(str[*i]==';') input+=str[(*i)++];
	    }
		return input;
	}
	return input;
}

string IFgt(string str, int *i){
	string input="";
	int cont=0;
	skipSpace(str,i);
	if(str[*i]=='{'){
		cont++;
		input+=str[*i];
		(*i)++;
		while( cont ){
			if(str[*i]=='{'){ cont++;  }
			if(str[*i]=='}'){
			    cont--;
			    if( cont==0){ input+=str[*i]; (*i)++; break;}
			}
			input+=str[*i];
			(*i)++;
		}
	}else{
        while(str[*i]!=';' && str[*i]!=0&& (*i)<str.length()){
			input+=str[(*i)++];

			if(input=="for" || input=="while"){
			input+=copyBoolean(str,i);
				skipSpace(str,i);
			input+= WFgt(str,i);
			break;
			}else if(input=="if"){
		        input+=copyBoolean(str,i);
		        skipSpace(str,i);
		        input+= IFgt(str,i);
				break;
			}
		}
		if(str[*i]!=0&& (*i)<str.length())
	    {
	        if(str[*i]==';'){input+=str[(*i)++];}
    	}
	}
	skipSpace(str,i);

	if( (*i)<str.length()){
		if(str[*i]=='e'&&str[(*i)+1]=='l'&&str[(*i)+2]=='s'&&str[(*i)+3]=='e'){
		    (*i)=(*i)+4;

		    skipSpace(str,i);
		    if(str[(*i)-1]==' '&&str[(*i)]=='i'&&str[(*i)+1]=='f'){
			    (*i)=(*i)+2;
			    input+="else if";
			    skipSpace(str,i);
			    input+=copyBoolean(str,i);

			    input+=IFgt(str,i);
				return input;
			}else{
			    input+="else ";
			    input+=WFgt(str,i);

			    return input;
			}
		}
	}
}

string copyContent(string file,int *i){
    string content;

	int cont =0;
	int state=0;

	skipSpace(file,i);
	if(file[*i]=='{'){
		cont++;
		(*i)++;
		while( cont ){
			if(file[*i]=='{'){ cont++;  }
			if(file[*i]=='}'){
			    cont--;
			    if(cont==0){(*i)++; break;}
			}
			content+=file[*i];
			(*i)++;
		}
	return content ;
	}
}

string copyContent_semi(string file,int *i){
    string content="";
	skipSpace(file,i);

	while(file[*i]!=';') content+=file[(*i)++];
	content+=file[(*i)++];
	return content;
}

/*
func: comput bool
*/
string copyBoolean(string file,int *i){
    string content="";

    skipSpace(file,i);
    if(file[*i]=='('){
		int cont=1;
		skipSpace(file,i);
        content+=file[*i];
	 	(*i)++;
	  	while( cont ){
			if(file[*i]=='('){ cont++;  }
			if(file[*i]==')'){
	            cont--;
	            if(cont==0){
                    content+=file[*i];
					(*i)++;
					skipSpace(file,i);
					while(file[*i]==')'){
					cout<<"\nError! Too many ')'!! \n"<<endl;
					is_error=true;
					(*i)++;
					}
					break;
				}
	        }
			content+=file[*i];
			(*i)++;
		}
	}
	return content ;
}

bool computebool (string boolean, int assem ){

    int state=0;
    // state =0  '<'
    // =1   '>'
    //=2   '=='
    //=3   '<='
    //=4   '>='

    int i=0;
    string A;
    skipSpace(boolean,&i);

	skipSpace(boolean,&i);
    int a=0;
	if(boolean[i]=='('){i++;}
	    while (boolean[i]!='<'  && boolean[i]!='>' && boolean[i]!='=' &&boolean[i]!=' '&&boolean[i]!='+'&&boolean[i]!='-'){
	        A+=boolean[i];
	        i++;
    }
    a=compute_int(A);


    skipSpace(boolean,&i);
	if(i<boolean.length() &&boolean[i]!=' '){

	    if(boolean[i]=='<'){
	        if(boolean[i+1]=='='){
	            //  <=
	            state=3;
	            i=i+2;
	        }
	        else{state=0; i=i+1; }
	    }else if(boolean[i]=='>'){
	        if(boolean[i+1]=='='){
	            //  <=
	            state=4;
	            i=i+2;
	        }
	        else{
				state=1;
				i=i+1;
			}
	    }else if (boolean[i]=='='&& boolean[i+1]=='='){
            state=2;
        	i=i+2;
        }else {
			cout<<"\nerror!\n";
			is_error=true;
		}
		skipSpace(boolean,&i);

	    string B;
	    int b=0;
		int c=0;
	    while (i<boolean.length() &&boolean[i]!=' '){
                if(boolean[i]=='(')
                    {
                        c++;
                    }
                if(boolean[i]==')')
                    {
                        c--;
                        if(c<0){
                            break;
                        }


                        }
                B+=boolean[i];
                i++;
                }


		b=compute_int(B);

		if(assem==0){
				switch(state){
					case 0:
					    if(a<b){return true;}
					    else{return false; }
					    break;
					case 1:
					    if(a>b){return true;}
					    else{return false;}
					    break;
					case 2:
					    if(a==b){return true;}
					    else{return false;}
					    break;
					case 3:
					    if(a<=b){return true;}
					    else{return false;}
					    break;

					case 4:
					    if(a>=b){return true;}
					    else{return false;}
					    break;
				}
		}
		else assembly_computebool_two(A ,state,B);
	}else {
	    if(assem==0){
			if(a!=0) return true;
			else return false;
		    }
	    else{assembly_computebool_one(A); }
	}

	// a??a–·a￠?a??a?¯a?|a??c??
}


// int
void int_func(string str, bool assem){
	bool check=1, check_neg=0;
	string key="", value_str="";
	int value=0;
	for(int i=0; i<str.length(); i++){
		if(str[i]!=' ' && str[i]!='\t' && str[i]!='\n' && int(str[i])!=0){
			if(check==1){
				if(str[i]=='='){
					if(key!="") check=0;
					else{
						cout<<"int_declare_error"<<endl;
						is_error=true;
						return;
					}
				}else if(str[i]==';'){
					value_str="0";
					break;
				}else key+=str[i];
			}else{
				if(str[i]==';') break;
				else{
					value_str+=str[i];
				}
			}
		}
	}
	value=compute_int(value_str);

	if(assem==0){
		if(is_variable_declare(key)){
			cout<<"int_redeclaration"<<endl;
			is_error=true;
			return;
		}
		variable.insert(pair<string,int>(key,value));
	}
	if(assem==1) assembly_int(key,value);
	return;
}

bool is_variable_declare(string str){
	map<string,int>::iterator l_it;
	if(variable.find(str)==variable.end()) return false;
	else return true;
}

int call_variable(string key){
	if(is_variable_declare(key)){
		return variable[key];
	}else{
		cout<< key << " the_variable_is_not_declare"<<endl;
		is_error=1;
		return -1;
	}
}

// printf
void printf_func(string str, bool assem){
	vector<string> output_fragment;
	vector<string> int_fragment;
	string output="";
	bool check_str=0, check_end=0;
	int parentheses=0;

	int i=0;
	while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;

	if(str[i]=='('){
		i++;
		while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;
		if(str[i]=='"'){	// first "
			while(check_end==0){
				if(i+1<str.length()) i++;
				else{
					is_error=true;
					cout<<"printf_compiler_error1"<<endl;
					return;
				}
				if(str[i]=='\\'){
					if(str[i+1]=='n') output+='\n';
					else if(str[i+1]=='t') output+='\t';
					else if(str[i+1]=='\\') output+='\\';
					else output+=str[i+1];
					i++;
				}else if(str[i]=='"'){
					i++;
					while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;
					if(str[i]==')'){
						output_fragment.push_back(output);
						output="";
						i++;
						while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;

						if(str[i]==';'){
							check_end=1;
						}
						else{
							is_error=true;
							cout<<"printf_compiler_error4"<<endl;
							return;
						}
					}else if(str[i]=='"') i+=2;
					else if(str[i]==','){	// ,
						output_fragment.push_back(output);
						output="";

						while(check_end==0){
							if(i+1<str.length()) i++;
							else{
								is_error=true;
								cout<<"printf_compiler_error1"<<endl;
								return;
							}
							while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;
							if(str[i]=='(') parentheses++;
							if(str[i]==')'){
								if(parentheses==0){
									int_fragment.push_back(output);
									output="";
									i++;
									while((str[i]==' ' || str[i]=='\t' || str[i]=='\n' || int(str[i])==0) && i+1<str.length()) i++;

									if(str[i]==';') check_end=1;
									else{
										is_error=true;
										cout<<"printf_compiler_error4"<<endl;
										return;
									}
								}else{
									parentheses--;
									output+=str[i];
								}
							}else if(str[i]==','){
								int_fragment.push_back(output);
								output="";
							}else{
								output+=str[i];
							}

						}
					}
				}else if(str[i]=='%' && str[i+1]=='d'){
					output_fragment.push_back(output);
					output="";
					output_fragment.push_back("%d");
					i++;
				}else{
					output+=str[i];
				}
			}
		}else{
			is_error=true;
			cout<<"printf_compiler_error2"<<endl;
			return;
		}
	}else{
		is_error=true;
		cout<<"printf_compiler_error3"<<endl;
		return;
	}

	if(assem==0){
		int int_num=-1;
		for(int j=0; j<output_fragment.size(); j++){
			if(output_fragment[j]=="%d") cout<<compute_int(int_fragment[++int_num]);
			else cout<<output_fragment[j];
		}
	}
	if(assem==1){
		int int_num=-1;
		for(int j=0; j<output_fragment.size(); j++){
			if(output_fragment[j]=="%d") assembly_printf_int(int_fragment[++int_num]);
			else assembly_printf_str(output_fragment[j]);
		}
	}
	return;
}

void push(char item){
	if (top>=N-1) printf("Stack full!\n");
	stack[++top]=item;
}

int pop(){
	if (top==-1) printf("Stack empty!\n");
	return stack[top--];
}

bool IsEmpty(void){
    if(top<0)
	return  true;
	return false;
}

bool IsFull(){
	if(top>=N-1)
	return true;
	return false;
}

char top_data(){
	return stack[top];
}

void clearblank( char inorder[]){
    int n=0;
	for(int k=0 ; k<strlen(inorder) ; k++)
    if(inorder[k]!=' ' && inorder[k]!='\n' && inorder[k]!='\t' &&inorder[k]!='\0')
        inorder[n++] = inorder[k];
        inorder[n]=0;

}

int priority(char c){
	int i;
	for( i=0; i < 5; i++)
	if(op[i] == c)
	return op_priority[i];
	return -1;
}

bool IsDight(char c){
	return c>='0' && c<='9';
}

vector<string> to_postorder(char inorder[], char postorder[]){
	int i=0, j=-1;
	char x, y;
	vector<string> postorder_vector;
	while((x=inorder[i]) != '\0'){
		switch(x){
			case '(' : push(x);
					   break;
			case ')' : while(! IsEmpty() && (x=pop()) != '('){


						char ctmp[] = {x,'\0'};
						postorder_vector.push_back(ctmp);}
						break;
			case '-' :
                    y=top_data();

                    if(y=='('||i==0){stringstream ss;
                                string stmp;
                                ss << 0;
                                ss >> stmp;
                                postorder_vector.push_back(stmp);}
					while(priority(y) >= priority(x)){
							//postorder[++j]=pop();
							char popChar = pop();
							//++j;
							char ctmp[] = {popChar,'\0'};
							postorder_vector.push_back(ctmp);;
							y=top_data();
					}
					push(x);
					break;
			case '+' :
			case '*' :
			case '/' : y=top_data(); //if stack's priority >= input's then pop the stack and put it into postorder

                    //push('0');
					while(priority(y) >= priority(x)){
							//postorder[++j]=pop();
							char popChar = pop();
							//++j;
							char ctmp[] = {popChar,'\0'};
							postorder_vector.push_back(ctmp);;
							y=top_data();
					}
					push(x);
					break;
			default :/*(A_) (_A) (A123) (A~z)*/
				if(!IsDight(inorder[i]))
				{
					string temp;
					while(IsDight(inorder[i]) || (inorder[i]>='A' && inorder[i]<='Z') || (inorder[i]>='a' && inorder[i]<='z') ||inorder[i]=='_'  )
					{
						char tmpChar [] ={inorder[i],'\0'};
						temp.append(tmpChar);
						i++;
					}
					i--;
					postorder_vector.push_back(temp);
				}
				else{
				    int value=0;
	               	while(IsDight(inorder[i])){
	                	value=value*10+(inorder[i]-48);
	                	i++;
	                }
	                i--;
	                stringstream ss;
	                string stmp;
	                ss << value;
	                ss >> stmp;
	                postorder_vector.push_back(stmp);
            		}
		}
		i++;
	}
	while(! IsEmpty())
	{
		char popChar = pop();
		char ctmp[] = {popChar,'\0'};
		postorder_vector.push_back(ctmp);
		++j;
	}

	return postorder_vector;
}

void declare_variable(string key, int value){
	variable.insert(pair<string,int>(key,value));
	return;
}



int calculate(vector<string> postorder){
	bool view_first = false;
	int a=0,b=0;
	string sa,sb;
	int size = postorder.size();
	vector<string> cal_string;

	for(int i=0;i<size;i++)
	{
		string spop = postorder.front();
		postorder.erase(postorder.begin());

		stringstream ss;
		int popInt;
		ss<<spop;
		if(ss>>popInt)
		{
			cal_string.push_back(spop);
		}
		else if((spop[0]!='+'&&spop[0]!='-'&&spop[0]!='*'&&spop[0]!='/' ))
		{
			cal_string.push_back(spop);
		}
		else
		{
			sa=cal_string.back();
			cal_string.erase(cal_string.end()-1);
			sb=cal_string.back();
			cal_string.erase(cal_string.end()-1);
			stringstream ssTest4;

			ssTest4<<sa;

			if(!(ssTest4>>a) ){
 				int temp = call_variable(sa);
				if(temp!=-1){
					a=temp;
				}
				else{
					cout << "variable_not_declare" <<endl;
					is_error=1;
				}
			}

			stringstream ssTest;
			ssTest<<sb;
 			if(! (ssTest>>b) ){
				int temp = call_variable(sb);
				if(temp!=-1){
					b=temp;
				}
				else{
					cout << "variable_not_declare" <<endl;
					is_error=1;
				}

			}

			switch(spop[0])
			{
		case'+':a=a+b;
				break;
		case'-':a=b-a;
				break;
		case'*':a=a*b;
				break;
		case'/':a=b/a;
				break;
			default:
				cout << "err spop" <<spop <<endl;
				is_error=1;
			}
			stringstream ssTest3;
			string sstemp;
			ssTest3<<a;
			ssTest3>>sstemp;
			cal_string.push_back(sstemp);
		}
	}
	stringstream ss;int popInt;
	string sPop = cal_string.back();

	ss<<sPop;
	ss>>popInt;
	return popInt;
}

string comput_assembly(string str){
	string assembly;

	int len=str.length();
	char inorder[len+10];
    strcpy(inorder, str.c_str());
    clearblank(inorder);
    vector<string> postorder = to_postorder(inorder,"");

    bool view_first = false;
	int a=0,b=0;
	string sa,sb;
	int size = postorder.size();
	vector<string> cal_string;
	bool isFirst=true;

	for(int i=0;i<size;i++)
	{
		string spop = postorder.front();
		postorder.erase(postorder.begin());

		stringstream ss;
		int popInt;
		ss<<spop;
		if(ss>>popInt)
		{
			cal_string.push_back(spop);
			assembly.append("push ").append(spop).append("\n");
		}
		else if((spop[0]!='+'&&spop[0]!='-'&&spop[0]!='*'&&spop[0]!='/' ))
		{
			cal_string.push_back(spop);
			assembly.append("push ").append(spop).append("\n");
		}
		else
		{
			sa=cal_string.back();
			cal_string.erase(cal_string.end()-1);
			assembly.append("pop  ebx").append("\n");
			sb=cal_string.back();
			cal_string.erase(cal_string.end()-1);
			assembly.append("pop  eax").append("\n");
			stringstream ss_assembly;
			ss_assembly<<sa;


			if(!(ss_assembly>>a) ){
 				int temp = call_variable(sa);
				if(temp!=-1){
					a=temp;
				}
				else{
					cout << "in sa err" <<endl;
				}

			}

			stringstream ssTest;
			ssTest<<sb;
 			if(! (ssTest>>b) ){
				int temp = call_variable(sb);
				if(temp!=-1){
					cout << sb << "= " << temp << endl;
					b=temp;
				}
				else{
					cout << "in sb err" <<endl;
				}
			}

			switch(spop[0])
			{
		case'+':a=a+b;
				assembly.append("add eax , ebx\n");
				break;
		case'-':a=b-a;
				assembly.append("sub eax , ebx\n");
				break;
		case'*':a=a*b;
				assembly.append("imul ebx\n");
				break;
		case'/':a=b/a;
				assembly.append("mov  edx , 0\n");
				assembly.append("idiv ebx\n");
				break;
			default:
				cout << "err spop" <<spop <<endl;
			}
			stringstream ssTest3;
			string sstemp;
			ssTest3<<a;
			ssTest3>>sstemp;
			cal_string.push_back(sstemp);
			assembly.append("push eax\n");
		  }

	}
	assembly.append("pop eax\n");
	assembly.append("mov temp , eax\n");
	return	assembly;

}

int compute_int(string str){
	str=str+"+0";
	//cout<<"original equation :"<<str<<endl;
	int len=str.length();
	char inorder[len+10], postorder[len];
    strcpy(inorder, str.c_str());


    clearblank(inorder);
    vector<string> res = to_postorder(inorder,postorder);
    int real_ans = calculate(res);
	return	real_ans;
}
void assembly_if(string boolean,string content,int Count,int index,bool next){
	//cout << char(index_count+63) << Count << ":" << endl;
	//toasm.append
	//toasm.append(">>>>\n");
	string opd;
	string leftopr="";
	string rightopr="";
	bool ch = true;
	int i=0;

	toasm.append("\n");
	toasm+=char(index+64);
	toasm.append(int_to_string(Count));
	toasm.append(":").append("\n");

	if(boolean.length()){
		computebool(boolean,1);
		//cout << "<<<<<" << endl;
		if(next){
			toasm+=char(index+64);
			toasm.append("next\n\n");
		}
		else{
			toasm+=char(index+64);
			toasm.append(int_to_string(Count+1));
			toasm.append("\n");
		}
	}


	exeFile(content,1);
	toasm.append("jmp ");
	toasm+=char(index+64);
	toasm.append("next\n\n");
	if(next){
		toasm+=char(index+64);
		toasm.append("next:\n");
	}

}

void assembly_for(string declare, string boolean, string compute, string content, int lcount){
	int i=0;
	string deopr;
	string strvalue;
	int devalue;
	bool ch=false;
	while(i<declare.length()){
		if(declare[i]=='i' && declare[i+1]=='n' && declare[i+2]=='t'){
			i+=3;
			ch=true;
			break;
		}
		else i++;
	}
	if(ch){
		skipSpace(declare,&i);
		int j=i;
		while(declare[j] != '=' && declare[j] !=' ' ) j++;
		strvalue.append(declare,i,j-i);

		exeFile(declare,0);
		exeFile(declare,1);
	}
	else updateValue(declare,1);


	toasm.append("\nLOOP").append(int_to_string(lcount)).append(":\n");
	computebool(boolean,1);
	toasm.append("LOOP").append(int_to_string(lcount)).append("next\n");
	exeFile(content,1);

	updateValue(compute,1);


	toasm.append("jmp LOOP").append(int_to_string(lcount)).append("\n\n");
	toasm.append("LOOP").append(int_to_string(lcount)).append("next:\n");
}



void assembly_while(string boolean, string content,int wcount){
	toasm.append("WHILE").append(int_to_string(wcount)).append(":\n");
	computebool(boolean,1);
	toasm.append("WHILE").append(int_to_string(wcount)).append("next\n");

	exeFile(content,1);
	//toasm.append(content);
	toasm.append("jmp WHILE").append(int_to_string(wcount)).append("\n\n");
	toasm.append("WHILE").append(int_to_string(wcount)).append("next:\n");

}

void assembly_int(string key, int value){
	string declare=key;
	declare.append(" DWORD ").append(int_to_string(value));
	declare.append("\n");
	toasm.insert(0,declare);
}

void assembly_printf_str(string content){
	int i=0;
	while(i<content.length()){

		if(content[i]=='\n') {
			toasm.append("call Crlf\n");
		}
        else if(content[i]=='\t'){
			for(int j=0;j<4;j++) toasm.append("mov edx,' '\n").append("call WriteChar\n");
		}
		else {
			toasm.append("mov al,\'");
			toasm+=content[i];
			toasm.append("\'\n");
			toasm.append("call WriteChar\n");
		}
		i++;
	}
}

void assembly_printf_int(string content){
	toasm.append(comput_assembly(content));
	if(compute_int(content)>0) toasm.append("call WriteDec\n");
	else toasm.append("call WriteInt\n");
}

void assembly_computebool_one(string A ){
	toasm.append(comput_assembly(A));
	toasm.append("mov ebx,1\ncmp ebx,temp\njb ");
}

void assembly_computebool_two(string A , int state , string B ){
	toasm.append(comput_assembly(A));
	toasm.append("mov ecx,temp\n");
	toasm.append(comput_assembly(B));
	toasm.append("cmp ecx,temp\n");
	switch(state){
		case 0:
			toasm.append("jnb ");
		    break;
		case 1:
		    toasm.append("jna ");
		    break;
		case 2:
		    toasm.append("jne ");
		    break;
		case 3:
		    toasm.append("ja ");
		    break;

		case 4:
		    toasm.append("jb ");
		    break;
	}
	return ;
}

void assembly_updatevalue(string A , int state , string B ){
	switch(state){
	    case 0:
	    	toasm.append(comput_assembly(B));
	    	toasm.append("mov ecx,temp\n").append("mov ").append(A).append(",ecx\n");
	        break;
	    case 1:
	    	toasm.append(comput_assembly(B));
	    	toasm.append("mov ecx,temp\n").append("sub ").append(A).append(",ecx\n");
	        break;
	    case 2:
	        toasm.append(comput_assembly(B));
	    	toasm.append("mov ecx,temp\n").append("add ").append(A).append(",ecx\n");
	        break;
	    case 3:
	        toasm.append("dec ").append(A).append("\n");
			break;
	    case 4:
	        toasm.append("inc ").append(A).append("\n");
	        break;
	    case 5:
	    	toasm.append(comput_assembly(B));
	    	toasm.append("mov ebx,temp\n").append("mov eax,").append(A).append("\n");
	    	toasm.append("imul ebx\n").append("mov ").append(A).append(",eax\n");
	        break;
	    case 6:
	        toasm.append(comput_assembly(B));
	    	toasm.append("mov ebx,temp\n").append("mov eax,").append(A).append("\n");
	    	toasm.append("idiv ebx\n").append("mov ").append(A).append(",eax\n");
	        break;
	    case -1:
	        cout<<"error!"<<endl;
	        return;
	}
	return;
}

string int_to_string (int value){

	string invertstr;
	string strvalue;
	if(value==0) strvalue+=char(value+48);
	while(value>0) {
		invertstr+=char((value%10)+48);
		value/=10;
	}
	int i=invertstr.length()-1;
	while(i>=0) strvalue+=invertstr[i--];
	return strvalue;
}


