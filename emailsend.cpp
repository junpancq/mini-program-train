#include <iostream>
#include <curl/curl.h>
#include <string>
#include <cstring>
using namespace std;
class curl{
	public:
		string smtpSever = "smtps://smtp.126.com:465",fromEmail="jun_pancq@126.com",userName = "jun_pancq@126.com",passWord="BDLHNQWGQONYJOPP",targetEmail="342264863@qq.com",emailTitle="test",content="test";
} BI;
void sendemail(curl& BI)
{
cout <<BI.smtpSever <<endl;
CURL * curl;
CURLcode res;
const char* cTargetEmail =BI.targetEmail.c_str();
size_t  length = BI.targetEmail.length();
char charTargetEmail[length+1];
strcpy(charTargetEmail,cTargetEmail);
curl  = curl_easy_init();
if(curl)
{
curl_easy_setopt(curl,CURLOPT_URL,BI.smtpSever);
//curl_easy_setopt(curl,BI.smtpSever);
curl_easy_setopt(curl,CURLOPT_USERNAME,BI.userName);
curl_easy_setopt(curl,CURLOPT_PASSWORD,BI.passWord);
curl_easy_setopt(curl,CURLOPT_MAIL_FROM,BI.fromEmail);

struct  curl_slist * recipients =  NULL;
recipients  = curl_slist_append(recipients,charTargetEmail);
curl_easy_setopt(curl,CURLOPT_MAIL_RCPT,recipients);

//curl_easy_setopt(curl,CURLOPT_SUBJECT,BI.emailTitle);
//curl_easy_setopt(curl,CURLOPT_MAIL_AUTH,BI.content);
//curl_easy_setopt(curl,CURLOPT_READDATA,stdin);
string  emailData = "Subject:" + BI.emailTitle + "\r\n";
	+ "To:" + BI.targetEmail + "\r\n";
	+ "From:" + BI.fromEmail + "\r\n\r\n"
	+ BI.content;
curl_easy_setopt(curl,CURLOPT_READDATA,emailData.c_str());
curl_easy_setopt(curl,CURLOPT_INFILESIZE,emailData.size());
res = curl_easy_perform(curl);
if(res!=CURLE_OK)
	fprintf(stderr,"curl_easy_perform() failed:%s\n",curl_easy_strerror(res));
curl_slist_free_all(recipients);
curl_easy_cleanup(curl);
//return 0;
}
}
int  main(){
	/*
cout << "Please Intput Your SmtpSever" << endl;
getline(cin,BI.smtpSever);

cout << "Please Intput Yout userName" << endl;
getline(cin,BI.userName);

cout << "Please Intput Your password" << endl;
getline(cin,BI.passWord);

cout << "please Intput Your fromemail" << endl;
getline(cin,BI.fromEmail);

cout << "Please Intput Your targetEmail" << endl;
getline(cin,BI.targetEmail);

cout << "Please Intput Your emailTitle" << endl;
getline(cin,BI.emailTitle);

cout << "Please Intput Your content" << endl;
getline(cin,BI.content);
	*/
sendemail(BI);
/*CURL *curl;
CURLcode res;
const char* cTargetEmail = BI.targetEmail.c_str();
size_t length  =  BI.targetEmail.length();

char charTargetEmail[length+1];
strcpy(charTargetEmail,cTargetEmail);
curl= curl_easy_init();
if(curl)
{
curl_easy_setopt(curl,CURLOPT_URL,BI.smtpSever);
curl_easy_setopt(curl,BI.smtpSever);
struct curl_slist *recipients = NULL;
recipients = curl_slist_append(recipients,charTargetEmail);
curl_easy_setopt(curl,CURLOPT_MAIL_RCPT,recipients);
curl_easy_setopt(curl,CURLOPT_READDATA,stdin);
res = curl_easy_perform(curl);
if(res!=CURLE_OK)
  fprintf(stderr,"curl_easy_perform() failed:%s\n",curl_easy_strerror(res));
curl_slist_free_all(recipients);
curl_easy_cleanup(curl);
*/
return 0;
//}
}
