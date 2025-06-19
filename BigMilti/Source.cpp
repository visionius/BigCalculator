///In the name of God
#include<iostream>
#include<string>

using namespace std;
string reverss(string input);
bool checkZero(string a);
string abss(string a);
string deleteZeros(string a);
string shiftStr(string a);
string gcd(string a,string b);

class BigNum
{
public:
	BigNum operator+(BigNum bn)
	{
		BigNum temp;
		int mind=0;
		number = reverss(number);
		bn.number = reverss(bn.number);
		if(number.length() > bn.number.length())
		{
			for(int i=bn.number.length();i<number.length();i++)
			{
				bn.number+="0";
			}
		}
		else
		{
			for(int i=number.length();i<bn.number.length();i++)
			{
				number+="0";
			}
		}
		bn.number = reverss(bn.number);
		number = reverss(number);
		for(int i=number.length()-1;i!=-1;i--)
		{
				int now1 = (number[i] - 48) + mind;
				int now2=0;
				if(((number.length() - bn.getNum().length()))<=i)
				{now2 = (bn.number[i-(number.length() - bn.getNum().length())]-48);}
				else
				{now2=0;}
				now1+=now2;
				if(mind != 0)
				{
					mind = 0;
				}
				if(now1>=10)
				{
					temp.number+=to_string((now1%10));
					mind = now1 /10;
				}
				else
				{
					temp.number +=to_string((now1));
				}
		}
		if(mind !=0)
		{
			temp.number+=to_string((mind));
			mind=0;
		}
		temp.number = reverss(temp.getNum());
		
		return temp;
	}
	BigNum operator*(BigNum bn)
	{
		BigNum temp;
		int mind=0;
		number = reverss(number);
		bn.number = reverss(bn.number);
		if(number.length() > bn.number.length())
		{
			for(int i=bn.number.length();i<number.length();i++)
			{
				bn.number+="0";
			}
		}
		else
		{
			for(int i=number.length();i<bn.number.length();i++)
			{
				number+="0";
			}
		}
		bn.number = reverss(bn.number);
		number = reverss(number);
		BigNum *a = new BigNum[number.length()*number.length()];
		int f =0;
		for(int i=number.length()-1;i!=-1;i--,f++)
		{
			
			for(int j=number.length()-1;j!=-1;j--)
			{
				int now1 = (bn.number[i] - 48) ;
				int now2=0;
				if(0<=j)
				{now2 = (number[j]-48);}
				else
				{now2=0;}
				now1*=now2;
				now1+= mind;
				if(mind != 0)
				{
					mind = 0;
				}
				if(now1>=10)
				{
					a[f].number+=to_string((now1%10));
					mind = now1 /10;
				}
				else
				{
					a[f].number +=to_string((now1));
				}
				

			}
			if(mind !=0)
			{
				a[f].number+=to_string((mind));
				mind=0;
			}
			a[f].number = reverss(a[f].number);
			for(int o =0;o<f;o++)
			{
				a[f].number+="0";
			}
		}


		for(int y=0;y<number.length()*number.length()-1;y++)
		{
			if(!checkZero(a[y+1].number))
				continue;
			a[0] = a[0] + a[y+1];
		}
		temp = a[0];
		temp.number = deleteZeros(temp.number);
		delete[] a;
		return temp;
	}
	BigNum operator-(BigNum bn)
	{
		BigNum temp;
		int mind=0;
		
		number = reverss(number);
		bn.number = reverss(bn.number);
		if(number.length() > bn.number.length())
		{
			for(int i=bn.number.length();i<number.length();i++)
			{
				bn.number+="0";
			}
		}
		else
		{
			for(int i=number.length();i<bn.number.length();i++)
			{
				number+="0";
			}
		}
		bn.number = reverss(bn.number);
		number = reverss(number);
		for(int i=number.length()-1;i!=-1;i--)
		{
			int now1 = (number[i]-48);
			int now2 = (bn.number[i]-48);
			int alamat = now1 - now2;///////////if min go into max we have the problem here

			if(alamat<0)
			{
				number[i-1] -=1;
				alamat = now1 +10 - now2;
				int t=0;
				for(;number[i-1-t]<'0';)
				{
				t++;
				number[i-1-t] -=1;
				}
				for(;t!=0;t--)
				{
					number[i-t] +=10;
				}
			}
			temp.number+=to_string(alamat);
		}
		temp.number = reverss(temp.number);
		temp.number = deleteZeros(temp.number);
		if (temp.number=="")
			temp.number="0";
		return temp;
	}
	BigNum operator/(BigNum bn)
	{
		BigNum temp;
		string finalResult,temps;
		unsigned long long int counter=0;
		BigNum chrt,minResult ,temp1,rikht;
		minResult.setNum(bn.getNum());
		temp1 = *this;
		int toolMax,toolMin,pos=0,start=0;
		toolMax = temp1.getNum().length();
		toolMin = bn.getNum().length();
		
		start = toolMin;
		int ck=0,ck2=0;
		if(toolMax >= toolMin && bn.number!="1")
		{
			for(int i=0;pos<toolMax; i++)
			{
				if(temps=="")
				{
					temps = temp1.number.substr(0,toolMin);
					chrt.number = chrt.number + temps;
					pos+=toolMin-1;
				}
				else
				{
					pos++;
					temps="";
					if(pos<toolMax)
					temps += temp1.number.substr(pos,1);
					if(temps=="0" && chrt.number!="")
					{chrt.number = chrt.number + temps;}
					if(temps=="0" && chrt.number=="")
					{
						finalResult+="0";
					}
					if(temps!="0" && temps!="")
					{
						chrt.number = chrt.number + temps;
					}
					if(!(((chrt.number>bn.number) && (chrt.number.length()==bn.number.length()))||chrt.number.length() > bn.number.length() || (chrt.number==bn.number)))
					{
						finalResult+="0";
					}
				}
				/////////do -
				for(int i=0;((chrt.number>bn.number) && (chrt.number.length()==bn.number.length()))||chrt.number.length() > bn.number.length() || (chrt.number==bn.number);i++)
				{
					minResult = chrt - bn;
					chrt = minResult;
					chrt.number = deleteZeros(chrt.number);
					counter++;
				}
				if(counter!=0)
				{
				finalResult+=to_string(counter);
				counter=0;
				continue;
				}
				if(pos==toolMax-1 && (chrt.number =="" || chrt.number<bn.number))
				{
					finalResult+="0";
				}
			}
			if(finalResult!="")
			{
				temp.number = finalResult;
			}
			else
			{
				temp.number = "0";
			}
		}
		else
		{
			if(bn.number=="1")
				temp.number=temp1.number;
			else if(toolMax < toolMin)
				temp.number ="0";
			return temp;
		}
		return temp;
	}
	BigNum operator%(BigNum bn)
	{
		BigNum temp;
		BigNum temp2;
		temp2 = *this;
		temp = temp2 / bn;
		temp = bn * temp;
		temp = temp2 - temp;
		return temp;
	}
	void setNum(string a)
	{
		number = a;
	}
	string getNum()
	{return number;}
	void addStr(string a)
	{number+=a;}
protected:
	string number;
};
void minesControl(BigNum num1 , BigNum num2,string op);
string reverss(string input)
{
	int tool = input.length();
	char c;
	for(int i=0;i<tool/2;i++)
	{
		c=input[i];
		input[i]=input[tool-1-i];
		input[tool-1-i]=c;
	}
	return input;
}
bool checkZero(string a)
{
	int ck=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='0')
		{
			ck =1;
		}
	}
	if(ck ==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
string deleteZeros(string a)
{
	string result;
	int ck=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='0')
		{
			ck =1;
		}
		if (ck==0)
		{
			continue;
		}
		result +=a[i];
	}
	return result;
}
string abss(string a)
{
	char c;
	string result="";
	
	if(a[0]=='-')
	{
		a = reverss(a);
		for(int i=0;i<a.length()-1;i++)
		{
			if(a[i]!='-')
			result += a[i];
		}
	}
	else
	{
		return a;
	}
	result = reverss(result);
	return result;
}
int main()
{
	BigNum num1,num2;
	//num1.setNum("128299637852747781491257187842028484364103855748297296704808405762229741626342194440837748106022068295635777844830831811978557490708404900063082674039252789841829590381008343327258960595508204744589399243877556198799438322881052857422197506822302290812621883700357890208069551876513290323124813780520689585503");
	string order;
	cin>> order;
	num1.setNum(order);
	cin>> order;
	num2.setNum(order);
	int num=0;
	cin>>num;
	BigNum tempp1,tempp2,num3;
	//tempp1.setNum("6822302389");
	//num3.setNum("65537");
	for(int i=0;i<1;i++)
	{

		num2 = num1 * num2;

		//tempp1 = tempp1 + tempp2;
		cout<<"----------------------------------------------"<<num2.getNum()<<endl;
		
	}
	cout<<num2.getNum()<<endl;
	//cout<<num1.getNum()<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>order;
		minesControl(num1,num2,order);
	}
}
void minesControl(BigNum num1 , BigNum num2,string op)
{
	string temp;
	BigNum result;
	if(num1.getNum()[0]=='-' && num2.getNum()[0] !='-')
	{
		temp = num1.getNum();
		temp[0]='0';
		temp = deleteZeros(temp);
		num1.setNum(temp);
		if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
		{
			if(op=="+")
			{
				
				result = num1-num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				result = num1 + num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				if(result.getNum()!="0")
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				result  = num1;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				result.setNum(gcd(num1.getNum(),num2.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				ads2.setNum(gcd(num1.getNum(),num2.getNum()));
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;
			}
		}
		else
		{
			if(op=="+")
			{
				
				result = num2-num1;
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				result = num1 + num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				if(result.getNum()!="0")
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				result  = num1;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				result.setNum(gcd(num1.getNum(),num2.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				ads2.setNum(gcd(num2.getNum(),num1.getNum()));///////////////////////////
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;
			}

		}
	}
	else if (num2.getNum()[0] =='-' && num1.getNum()[0]!='-')
	{
		temp = num2.getNum();
		temp[0]='0';
		temp = deleteZeros(temp);
		num2.setNum(temp);
		if((num2.getNum().length() >num1.getNum().length()||(num2.getNum().length() == num1.getNum().length() && num2.getNum() > num1.getNum())))
		{
			if(op=="+")
			{
				
				result = num2-num1;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				result = num1 + num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				if(result.getNum()!="0")
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				result  = num1;
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				result.setNum(gcd(num1.getNum(),num2.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				ads2.setNum(gcd(num2.getNum(),num1.getNum()));
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;
			}
		}
		else
		{
			if(op=="+")
			{
				
				result = num1-num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				result = num1 + num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				if(result.getNum()!="0")
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				result  = num1;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				result.setNum(gcd(num1.getNum(),num2.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				ads2.setNum(gcd(num1.getNum(),num2.getNum()));
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;
			}

		}
	}
	else if (num2.getNum()[0] =='-' && num1.getNum()[0]=='-')
	{
		temp = num2.getNum();
		temp[0]='0';
		temp = deleteZeros(temp);
		num2.setNum(temp);
		temp = num1.getNum();
		temp[0]='0';
		temp = deleteZeros(temp);
		num1.setNum(temp);

			if(op=="+")
			{
				result = num1+num2;
				result.setNum(shiftStr(result.getNum()));
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
				result = num1 - num2;
				result.setNum(shiftStr(result.getNum()));
				}
				else
				{
					result = num2 - num1;
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
				result = num1 % num2;
				}
				else
				{
					result = num2 % num1;
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
					result.setNum(gcd(num1.getNum(),num2.getNum()));
				}
				else
				{
					result.setNum(gcd(num2.getNum(),num1.getNum()));
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				
				
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
					ads2.setNum(gcd(num1.getNum(),num2.getNum()));
				}
				else
				{
					ads2.setNum(gcd(num2.getNum(),num1.getNum()));
				}
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;

			}
	}
	else if (num2.getNum()[0] !='-' && num1.getNum()[0]!='-')//////////////////////////equal
	{
			if(op=="+")
			{
				result = num1+num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "-")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
				result = num1 - num2;
				}
				else
				{
					result = num2 - num1;
					result.setNum(shiftStr(result.getNum()));
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "*")
			{
				result = num1 * num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "/")
			{
				result = num1 / num2;
				cout<<result.getNum()<<endl;
			}
			else if(op == "%")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
				result = num1 % num2;
				}
				else
				{
					result = num1;
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "abs")
			{
				result.setNum(abss(num1.getNum()));
				cout<<result.getNum()<<endl;
				result.setNum(abss(num2.getNum()));
				cout<<result.getNum()<<endl;

			}
			else if(op == "gcd")
			{
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
					result.setNum(gcd(num1.getNum(),num2.getNum()));
				}
				else
				{
					result.setNum(gcd(num2.getNum(),num1.getNum()));
				}
				cout<<result.getNum()<<endl;
			}
			else if(op == "lcm")
			{
				BigNum ads1,ads2;
				result = num1;
				
				
				if((num1.getNum().length() >num2.getNum().length()||(num1.getNum().length() == num2.getNum().length() && num1.getNum() > num2.getNum())))
				{
					ads2.setNum(gcd(num1.getNum(),num2.getNum()));
				}
				else
				{
					ads2.setNum(gcd(num2.getNum(),num1.getNum()));
				}
				ads1 = result / ads2;
				ads1 = ads1 * num2;
				result.setNum(ads1.getNum());
				cout<<result.getNum()<<endl;
			}
	}


}
string gcd(string a,string b)
{
	BigNum temp1,temp2,temp3,temp4;
	string result;
	temp4 .setNum("a");
	temp1.setNum(a);
	temp2.setNum(b);
	for(int i=0;temp4.getNum()!=temp3.getNum() && temp2.getNum()!="1";i++)
	{
		temp4= temp3;
		temp3 = temp1 % temp2;
		if(temp3.getNum()=="0")
		{
			break;
		}
		temp1= temp2;
		temp2= temp3;
	}
	result = temp2.getNum();
	return result;
}
string shiftStr(string a)
{
	string temp;
	temp +="-";
	for(int i =0;i<a.length();i++)
	{
		temp +=a[i];
	}
	return temp;
}