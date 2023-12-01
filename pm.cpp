#include <iostream>
#include <fstream> 
#include <ctime>
using namespace std;

ofstream outfile;
fstream thefile1;
fstream thefile2;
fstream thefile3;
int i, ix, x;
int rowX=0, rowY=0;;
char m1[100]; 
char xm1[100];
char a,a1; 
char date[100];
char setings[100] = "fshow.part.save";
char code[100] = "mysql_temp.tmp";
int b,s0, s1=1,s1a,s2,s3=0, id=2013;
string line;

void decoding(){
    for (ix=0; ix<100; ix++)
    xm1[ix]=m1[ix]+x;  	
}
void decode(){
    x=x*(-1);	
    ifstream thefile1 (code);  
       if(thefile1.is_open()){
            while(thefile1.peek()!=EOF){
                getline(thefile1, line);
                rowX++;
            }
            thefile1.close();
        }     
    thefile1.open(code, ios::in);
        for (i=0; i<rowX; i++){ 
            thefile1 >> m1 ;        
	        decoding();	
	        printf("%s\n", xm1); 
        }     
    thefile1.close();    
    printf("\n1-Options");
    printf("\n0-Exit\n");
    cin >> a;
    system("clear");
	if (a=='1'){	
	    cout<<("Options:\n");
	    cout<<("--------------\n");
	    cout<<"1-Edit TXT file\n";
	    cout<<"2-Change the number of wrong attempts befor Erase Data file("<<s1<<"):\n";
	    cout<<"3-Change the Encryption key ("<<s2<<"):\n";
	    cout<<"4-Change the Password\n";
	    cout<<"5-Erase ALL Data files\n";
	    cout<<"0-Exit\n";
	    
	    cin >> a1;
            	if (a1=='1'){
	            printf("\nCreating a y.txt' file...");
	            printf("\nDon't forget to SAVE the TXT file!");  
                    thefile1.open(code, ios::in);
                    thefile2.open("y.txt", ios::out);
                        for (i=0; i<rowX; i++){ 
                            thefile1 >> m1 ; 
	                    decoding();        
	                    thefile2 << xm1 << "\n";
                        }	
	            thefile1.close();
	            thefile2.close();
	            a='0';	
	            system ("y.txt");
	            system("editor y.txt");	            
	            printf("\nFinish editing? (y/n)"); 
	            cin >> a;
                    	if (a=='y'){   	  
                            thefile3.open(setings, ios::in);
                            thefile3 >>s0>> s1 >>  s2 >> s3>>  date ;
                            thefile3.close();	
                            thefile3.open(setings, ios::out);        
                            time_t now = time(0);
                            tm *ltm = localtime(&now);
		            thefile3 <<s0<<" "<< s1<<" "<<s2<<" "<<s3<<" "<<"Date:"<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/"<<1900+ltm->tm_year<<",Time:"<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
		            thefile3.close();						   	
	                    thefile1.open("y.txt", ios::in); 
                            ifstream thefile1 ("y.txt");  
                                if(thefile1.is_open()){
                                    while(thefile1.peek()!=EOF){
                                        getline(thefile1, line);
                                        rowY++;
                                    }
                                thefile1.close();  
                                }
	                    x=x*(-1);
	                    thefile1.open("y.txt", ios::in); 
	                    thefile2.open(code, ios::out); 
	                        for (i=0; i<rowY; i++){ 
                                    thefile1 >> m1;
                                    printf("%s\n", m1);  
	                                for (ix=0; ix<100; ix++)
	                                    xm1[ix]=m1[ix]+x;
                                                thefile2 << xm1 << "\n";		 
                                }
                        }
                    else{
	                remove("y.txt");
	                exit(0);
                        }
                    thefile1.close(); 
                    thefile1 >> x;
                    thefile1.open("y.txt", ios::out);
                    thefile1.close(); 
                    printf("\nErasing 'y.txt'...\n"); 
                    remove("y.txt");
                    system("clear");
                    exit(0);
	        }
	        	    	
	     	if(a1=='2'){
	         	printf("Erase Data file after x wrong attempts (0-Disable eraising):");
	         	cin >> s1;	
		}
	     	
	     	if(a1=='3'){
	         	system("clear");
	         	cout<<"Encryption key(2-8, Correct:"<<s2<<"):";
	         	cin >> s2;
	         	x=s2;
	         	system("clear");
		}
			
	        if(a1=='4'){
	                system("clear");
                        printf("Enter a new password: ");
	         	cin >> s3;
	         	system("clear");					
	        }
		 	
		if(a1=='5'){
             	        remove(code);
             		remove(setings);
             	        system("clear");
	         	exit(0);
		}
		 	
	     	if(a1=='0'){
	     	        system("clear");
	     	        exit(0);	
	        }
	        
	     	thefile3.open(setings, ios::out); 
                s3=s3+id;
                time_t now = time(0);
                tm *ltm = localtime(&now);
		thefile3 <<s0<<" "<< s1<<" "<<s2<<" "<<s3<<date;
		thefile3.close();
		system("clear"); 
	    	exit(0);
	}
	    
	if (a=='0'){
	    	system("clear");
	    	exit(0);
	}	
}

void run(){
    //system("Color 0A");
    //printf(" %c-So%ct\n\n",251,159); 
    cout<<"Vladi's Password Manager\n";
	    cout<<"*25.11.23*\n";
    cout<<"--------------------------------\n";
    cout<<"Last time Edited: "<<date<<"\n";
        if (x==0)
            printf("!!!CHANGE the Encryption key!!!\n");
    	if (s3==id||s3==911)
    	    printf("!!!CHANGE the Password!!!\n");	
    cout<<"--------------------------------\n";
	    
    decode();  	
}

void pass(){
    cin >> b;
    system("clear");
    	if (b==(s3))	
    	   run();		
    	if (s1==0)
	   pass();				    
        if (s1>0&&s1a>0){	
	    s1a--;	
	        if(s1a==0){	
	            thefile1.close();
               	    remove(code);
               	    remove(setings);
	            exit(0);   
	       	}
	    pass();
    	}   
}

int main() {
    system("clear");
    //system("Color 00");
    thefile3.open(setings, ios::in);
    thefile3 >>s0>> s1 >>  s2 >> s3>>  date ;
    thefile3.close(); 
        if (s3==0){	
    	    remove(code);
            remove(setings);
	}
        if(s3!=0)
            s3=s3-id;
        if(s3==0)
            s3=911;  
    x=s2;
    x=x*(-1);
    thefile3.close();
    s1a=s1;
    pass();
    system("attrib +h -s *code");
    return 0;
}
