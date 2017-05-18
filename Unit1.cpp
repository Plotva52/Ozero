//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <sstream>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int flag=0;
int flag1=0;
String Nomer1;
String Nomer;
String sht;
String result;
String result2;
String result3;
String result4;
String vivod;
String Nomer2;
String mes;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
String result="";
 String result2="";
 String result3="";
 String result4="";
  String Nomer="";
 String Nomer1="";
 String Nomer2="";


if((Edit1->Text=="")||(Edit1->Text=="+"))
{ShowMessage("Вы не указали номер телефона");}
else
{
//Цифры----------------------------------------------------------------------
int A;
  int i=1;
  char n;
  Nomer=Edit1->Text;

	if(Nomer[1]=='+')
	 {
		Nomer.Delete(1,1);
		flag1=1;
	 }
	A = Nomer.Length();

	sht=IntToHex(A,2);

   if(Nomer.Length()%2!=0)
   {
   Nomer+="F";
   flag=1;
   }

     while(i<Nomer.Length())
   {
	n=Nomer[i+1];
	Nomer[i+1]=Nomer[i];
	Nomer[i]=n;
	i=i+2;
   }

   Nomer1="000100"+sht+"91"+Nomer;

//Текст----------------------------------------------------------------------

 String result1;
 String str;
 str=Edit3->Text;
  TBytes ucs2;

   ucs2=TEncoding::Unicode->GetBytes(str);
   str="";
for (int i=0; i<ucs2.Length; i=i+2)
 {
   result=result+IntToHex(ucs2[i+1],2)+""+IntToHex(ucs2[i], 2);
 }
 String Len = IntToHex((str.Length())*2, 2);

Memo1->Lines->Add(Nomer1+"0008"+Len+result);
}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if(Edit2->Text=="")
{ShowMessage("Вы не ввели PDU");
}
else
{
String m1;
String message;


int i=1;
int l=1;
 char n;
 String plus;
  message=Edit2->Text;

 AnsiString len = message.SubString(7, 2);
   std::string hex;
	hex = len.c_str();
	std::istringstream stream(hex);
	int dec;
	stream >> std::hex >> dec;




  //Memo2->Lines->Clear();

   message.Delete(1,10);

   Nomer2=message;
   if(dec%2==0)
   Nomer2=Nomer2.Delete(1,dec+1);
   else
   Nomer2=Nomer2.Delete(1,dec);



   while(i<=dec)
   {
	n=message[i];
	message[i]=message[i+1];
	message[i+1]=n;
	i=i+2;
   }

	message.Delete(dec+1,message.Length());
	Memo2->Lines->Add(message);
//----Текст---------------------------------------------------------------------




mes=Edit2->Text;
if (dec%2!=0) {
mes=mes.Delete(1,dec+17);
}
else mes=mes.Delete(1,dec+16);
 String r;
String Str;
String Str1;
for (int i = 1; i <mes.Length(); i+=4) {
 Str1=mes.SubString(i,4);

 Str=wchar_t(StrToInt("0x"+Str1));
 r=r+""+Str;
 Str="";
 Str1="";
}

 Memo2->Lines->Add(r);




  }

 }







//---------------------------------------------------------------------------




void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if( Key != 8 && ( (Key < '0' || Key > '9' ) ) ) Key = NULL;
    else if( Key == 8 && Edit1->Text.Length() == 1 && Edit1->Text[1] == '+')
        Key = NULL;

	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
Memo1->Clear();
Memo2->Clear();
}
//---------------------------------------------------------------------------

