#include<iostream>
#include<string>
#include<sstream>
using namespace std;
long concat(int a,int b,int c)
{
    long d;
    d=(a*10000)+(b*100)+(c);
    return d;
}
void sub(int m1,int m2,int h1,int h2,int *diffm,int *diffh)
{
	if(m1<m2)
	{
		*diffm=60-(m2-m1);
		h1--;
		*diffh=h1-h2;
	}
	else
	{
		*diffm=m1-m2;
		*diffh=h1-h2;
	}
}
void add(int m1,int m2,int h1,int h2,int *addm,int *addh)
{
	int m,hinc=0;
	cout<<endl<<m1<<endl;
	cout<<endl<<m2<<endl;
	cout<<endl<<h1<<endl;
	cout<<endl<<h2<<endl;
	if((m1+m2)>60)
	{
		while((m1+m2)>60)
		{
			m=(m1+m2)-60;
			hinc++;
		}
		*addm=m;
		*addh=h1+h2+hinc;
	}
	else
    {
        *addm=m1+m2;
		*addh=h1+h2+hinc;
    }
	cout<<endl<<*addm<<endl;
	cout<<endl<<*addh<<endl;
}
int main()
{
	system("cls");
	int date[100],month[100],year[100],mdate[100],mmonth[100],myear[100],hours[100],mine[100],tpmul=0,wpmul=0,cmul=0,tepmul=0,k=0,i=0,j=1,t=0,n,w=0,d=0,c,wmuli=0,m,muldate,muldate1,muldate2,muln,mmuln,wdl,citycmp,wrate,travelnetperc,worknetperc,travelnetrate,worknetrate,addansh=0,addansm=0,ansh=0,ansm=0,cnt=0,ip=0,q,p,uniindex[50],rate;
	long *travelfdateh=new long[999999],*travelfdatem=new long[999999],*workfdateh=new long[999999],*workfdatem=new long[999999],*percenttravelfdate=new long[999999],*ratetravelfdate=new long[999999],*percentworkfdate=new long[999999],*rateworkfdate=new long[999999],*totalamountfdate=new long[999999],*overtimefdate=new long[999999];
    std::string city[100],temp="nothing",evalcity,acity="ahemdabad";
	while(city[0]!=temp)
	{
		cout<<"please enter the name of city departing form"<<endl;
		cin>>city[k];
		cout<<"please enter the departing time"<<endl;
		cout<<"hours :";
		cin>>hours[k];
		cout<<endl<<"minutes :";
		cin>>mine[k];
		temp=city[k];
		cout<<"please enter the date of departing"<<endl;
		cout<<"day:";
		cin>>date[k];
		cout<<endl<<"month:";
		cin>>month[k];
		cout<<endl<<"year:";
		cin>>year[k];
		travelfdateh[concat(date[k],month[k],year[k])]=0;
		travelfdatem[concat(date[k],month[k],year[k])]=0;
		workfdateh[concat(date[k],month[k],year[k])]=0;
		workfdatem[concat(date[k],month[k],year[k])]=0;
		k++;
		cout<<"please enter the name of destination city"<<endl;
		cin>>city[k];
		cout<<"please enter the reaching time of destination"<<endl;
		cout<<"hours :";
		cin>>hours[k];
		cout<<endl<<"minutes :";
		cin>>mine[k];
		temp=city[k];
		cout<<"please enter the date of arrival at destination"<<endl;
		cout<<"day:";
		cin>>date[k];
		cout<<endl<<"month:";
		cin>>month[k];
		cout<<endl<<"year:";
		cin>>year[k];
		travelfdateh[concat(date[k],month[k],year[k])]=0;
		travelfdatem[concat(date[k],month[k],year[k])]=0;
		workfdateh[concat(date[k],month[k],year[k])]=0;
		workfdatem[concat(date[k],month[k],year[k])]=0;
		k++;



	}

	n=k;



	for(wdl=0;wdl<n;wdl++)
	{
		if(wmuli%2!=0  && wmuli!=0)
		{
			if((date[wmuli])+1!=date[wmuli+1] && date[wmuli]!=date[wmuli+1])
			{
				if((month[wmuli]==month[wmuli+1]) && (year[wmuli]==year[wmuli+1]))
				{
					muldate=date[wmuli+1]-date[wmuli];
					muln=date[wmuli];
					muln++;
					for(m=0;m<muldate-1;m++)
					{
						mdate[cmul]=muln;
						mmonth[cmul]=month[wmuli];
						myear[cmul]=year[wmuli];
						travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
						workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						percentworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
						overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						evalcity=city[wmuli];
						citycmp=evalcity.compare(acity);
						if(citycmp==0)
						{
							rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
							totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
						}
						else
						{
							rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
							totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
						}
						muln++;
						cmul++;
					}
				}
				if((month[wmuli]!=month[wmuli+1]) && (year[wmuli]==year[wmuli+1]))
				{
					if(month[wmuli]==1 || month[wmuli]==3 || month[wmuli]==5 || month[wmuli]==7 || month[wmuli]==8 || month[wmuli]==10 || month[wmuli]==12)
					{
						muldate1=31-date[wmuli];
						muldate2=date[wmuli+1];
						muldate=muldate1+muldate2;
						muln=date[wmuli];
						mmuln=month[wmuli];
						muln++;
						for(m=0;m<muldate-1;m++)
						{
							mdate[cmul]=muln;
							mmonth[cmul]=mmuln;
							myear[cmul]=year[wmuli];
							if(muln==31)
							{
								muln=0;
								mmuln++;
							}
							travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
							workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							percentworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
							overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							evalcity=city[wmuli];
							citycmp=evalcity.compare(acity);
							if(citycmp==0)
							{
								rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
								totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
							}
							else
							{
								rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
								totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
							}
							muln++;
							cmul++;
						}
					}
					if(month[wmuli]==2 || month[wmuli]==4 || month[wmuli]==6 || month[wmuli]==9 || month[wmuli]==11)
					{
						if(month[wmuli]==2)
						{
							muldate1=28-date[wmuli];
							muldate2=date[wmuli+1];
							muldate=muldate1+muldate2;
							muln=date[wmuli];
							mmuln=month[wmuli];
							muln++;
							for(m=0;m<muldate-1;m++)
							{
								mdate[cmul]=muln;
								mmonth[cmul]=mmuln;
								myear[cmul]=year[wmuli];
								if(muln==28)
								{
									muln=0;
									mmuln++;
								}
								travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
								travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
								workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
								workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
								percentworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
								overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
								evalcity=city[wmuli];
								citycmp=evalcity.compare(acity);
								if(citycmp==0)
								{
									rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
									totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
								}
								else
								{
									rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
									totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
								}
								muln++;
								cmul++;
							}
						}

						muldate1=30-date[wmuli];
						muldate2=date[wmuli+1];
						muldate=muldate1+muldate2;
						muln=date[wmuli];
						mmuln=month[wmuli];
						muln++;
						for(m=0;m<muldate-1;m++)
						{
							mdate[cmul]=muln;
							mmonth[cmul]=mmuln;
							myear[cmul]=year[wmuli];
							if(muln==30)
							{
								muln=0;
								mmuln++;
							}
							travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
							workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							percentworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
							overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							evalcity=city[wmuli];
							citycmp=evalcity.compare(acity);
							if(citycmp==0)
							{
								rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
								totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
							}
							else
							{
								rateworkfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=420;
								totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=560;
							}
							muln++;
							cmul++;
						}
					}
				}
			}
		}
		else
		{
			if((date[wmuli])+1!=date[wmuli+1] && date[wmuli]!=date[wmuli+1])
			{
				if((month[wmuli]==month[wmuli+1]) && (year[wmuli]==year[wmuli+1]))
				{
					muldate=date[wmuli+1]-date[wmuli];
					muln=date[wmuli];
					muln++;
					for(m=0;m<muldate-1;m++)
					{
						mdate[cmul]=muln;
						mmonth[cmul]=month[wmuli];
						myear[cmul]=year[wmuli];
						travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
						travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						percenttravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
						ratetravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						muln++;
						cmul++;
					}
				}
			}
			if((month[wmuli]!=month[wmuli+1]) && (year[wmuli]==year[wmuli+1]))
			{
				if(month[wmuli]==1 || month[wmuli]==3 || month[wmuli]==5 || month[wmuli]==7 || month[wmuli]==8 || month[wmuli]==10 || month[wmuli]==12)
				{
					muldate1=31-date[wmuli];
					muldate2=date[wmuli+1];
					muldate=muldate1+muldate2;
					muln=date[wmuli];
					mmuln=month[wmuli];
					muln++;
					for(m=0;m<muldate-1;m++)
					{
						mdate[cmul]=muln;
						mmonth[cmul]=mmuln;
						myear[cmul]=year[wmuli];
						if(muln==31)
						{
							muln=1;
							mmuln++;
						}
						travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
						travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						percenttravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
						ratetravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						muln++;
						cmul++;
					}
				}
				if(month[wmuli]==2 || month[wmuli]==4 || month[wmuli]==6 || month[wmuli]==9 || month[wmuli]==11)
				{
					if(month[wmuli]==2)
					{
						muldate1=28-date[wmuli];
						muldate2=date[wmuli+1];
						muldate=muldate1+muldate2;
						muln=date[wmuli];
						mmuln=month[wmuli];
						muln++;
						for(m=0;m<muldate-1;m++)
						{
							mdate[cmul]=muln;
							mmonth[cmul]=mmuln;
							myear[cmul]=year[wmuli];
							if(muln==28)
							{
								muln=1;
								mmuln++;
							}
							travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
							travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							percenttravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
							ratetravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
							totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
							overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
							muln++;
							cmul++;
						}
					}
					muldate1=30-date[wmuli];
					muldate2=date[wmuli+1];
					muldate=muldate1+muldate2;
					muln=date[wmuli];
					mmuln=month[wmuli];
					muln++;
					for(m=0;m<muldate-1;m++)
					{
						mdate[cmul]=muln;
						mmonth[cmul]=mmuln;
						myear[cmul]=year[wmuli];
						if(muln==30)
						{
							muln=1;
							mmuln++;
						}
						travelfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=24;
						travelfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdateh[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						workfdatem[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						percenttravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=100;
						ratetravelfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						totalamountfdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=340;
						overtimefdate[concat(mdate[cmul],mmonth[cmul],myear[cmul])]=0;
						muln++;
						cmul++;
					}
				}
			}
		}
		wmuli++;
	}

	for(t=0;t<(n/2);t++)
	{
		if(date[i]==date[i+1] && month[i]==month[i+1] && year[i]==year[i+1])
		{
			sub(mine[i+1],mine[i],hours[i+1],hours[i],&ansm,&ansh);
			add((travelfdatem[concat(date[i],month[i],year[i])]),ansm,(travelfdateh[concat(date[i],month[i],year[i])]),ansh,&addansm,&addansh);
			travelfdateh[concat(date[i],month[i],year[i])]=addansh;
			travelfdatem[concat(date[i],month[i],year[i])]=addansm;

			if((i+1)==(n-1))
            {
                break;
            }
			i=i+2;
        }
		if(date[i]!=date[i+1] || month[i]!=month[i+1] || year[i]!=year[i+1])
		{
			sub(00,mine[i],24,hours[i],&ansm,&ansh);
			add((travelfdatem[concat(date[i],month[i],year[i])]),ansm,(travelfdateh[concat(date[i],month[i],year[i])]),ansh,&addansm,&addansh);
			travelfdateh[concat(date[i],month[i],year[i])]=addansh;
			travelfdatem[concat(date[i],month[i],year[i])]=addansm;

            add((travelfdatem[concat(date[i+1],month[i+1],year[i+1])]),mine[i+1],(travelfdateh[concat(date[i+1],month[i+1],year[i+1])]),hours[i+1],&addansm,&addansh);
			travelfdateh[concat(date[i+1],month[i+1],year[i+1])]=addansh;
			travelfdatem[concat(date[i+1],month[i+1],year[i+1])]=addansm;
			if((i+1)==(n-1))
            {
                break;
            }
			i=i+2;
		}
	}

	for(w=0;w<(n/2)-1;w++)
	{
		if(date[j]==date[j+1] && month[j]==month[j+1] && year[j]==year[j+1])
		{
			sub(mine[j+1],mine[j],hours[j+1],hours[j],&ansm,&ansh);
			add((workfdatem[concat(date[j],month[j],year[j])]),ansm,(workfdateh[concat(date[j],month[j],year[j])]),ansh,&addansm,&addansh);
			workfdateh[concat(date[j],month[j],year[j])]=addansh;
			workfdatem[concat(date[j],month[j],year[j])]=addansm;
			if((j+1)==(n-2))
            {
                break;
            }
			j=j+2;
		}
		if(date[j]!=date[j+1] || month[j]!=month[j+1] || year[j]!=year[j+1])
		{
			sub(00,mine[j],24,hours[j],&ansm,&ansh);
			add((workfdatem[concat(date[j],month[j],year[j])]),ansm,(workfdateh[concat(date[j],month[j],year[j])]),ansh,&addansm,&addansh);
			workfdateh[concat(date[j],month[j],year[j])]=addansh;
			workfdatem[concat(date[j],month[j],year[j])]=addansm;

			add((workfdatem[concat(date[j+1],month[j+1],year[j+1])]),mine[j+1],(workfdateh[concat(date[j+1],month[j+1],year[j+1])]),hours[j+1],&addansm,&addansh);
			workfdateh[concat(date[j+1],month[j+1],year[j+1])]=addansh;
			workfdatem[concat(date[j+1],month[j+1],year[j+1])]=addansm;
            if((j+1)==(n-2))
            {
                break;
            }
			j=j+2;
		}
	}

    for(q=0;q<n;q++)
    {
        cnt=0;
        for(p=q+1;p<n;p++)
        {
            if(date[q]==date[p])
            {
                cnt++;
            }
        }
        if(cnt==0)
        {
            uniindex[ip]=q;
            ip++;
        }
    }

	for(d=0;d<ip;d++)
	{
        rate=travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
        if(0<rate && rate<=6)
        {
            percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=30;
            ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=102;
        }
        if(6<rate && rate<=12)
        {
            percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=50;
            ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=170;
        }
        if(12<rate && rate<=24)
        {
            percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=100;
            ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=340;
        }
	}

    cout<<endl<<"travel evaluation"<<endl;
    for(d=0;d<ip;d++)
	{
	    if(d+1==ip)
        {
            cout<<endl<<endl;
			cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
			cout<<"Time spent in traveling :-"<<endl;
			cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
			cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
            break;
        }
	    if((date[uniindex[d]])+1!=date[uniindex[d+1]] && date[uniindex[d]]!=date[uniindex[d+1]])
		{
            if((month[uniindex[d]]==month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
            {

				cout<<endl<<endl;
                cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
                cout<<"Time spent in traveling :-"<<endl;
                cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
                cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

				muldate=date[uniindex[d+1]]-date[uniindex[d]];
				for(m=0;m<muldate-1;m++)
                {
                    cout<<endl<<endl;
                    cout<<mdate[tpmul]<<"/"<<mmonth[tpmul]<<"/"<<myear[tpmul]<<" :-"<<endl;
                    cout<<"Time spent in traveling :-"<<endl;
                    cout<<travelfdateh[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" hours  "<<travelfdatem[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" minutes"<<endl;
                    cout<<"Percent :- "<<percenttravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<"%   Rate:-"<<ratetravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<endl;
                    tpmul++;
                }
				if(d+1==ip)
				{
					cout<<endl<<endl;
					cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
					d++;
				}
            }
			if(d==ip)
			{
				break;
			}
			if((month[uniindex[d]]!=month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
			{
				if(month[uniindex[d]]==1 || month[uniindex[d]]==3 || month[uniindex[d]]==5 || month[uniindex[d]]==7 || month[uniindex[d]]==8 || month[uniindex[d]]==10 || month[uniindex[d]]==12)
				{
					cout<<endl<<endl;
					cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=31-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<mdate[tpmul]<<"/"<<mmonth[tpmul]<<"/"<<myear[tpmul]<<" :-"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" hours  "<<travelfdatem[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percenttravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<"%   Rate:-"<<ratetravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<endl;
						tpmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
				if(month[uniindex[d]]==2 || month[uniindex[d]]==4 || month[uniindex[d]]==6 || month[uniindex[d]]==9 || month[uniindex[d]]==11)
				{
					if(month[uniindex[d]]==2)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

						muldate1=28-date[uniindex[d]];
						muldate2=date[uniindex[d+1]];
						muldate=muldate1+muldate2;
						for(m=0;m<muldate-1;m++)
						{
							cout<<endl<<endl;
							cout<<mdate[tpmul]<<"/"<<mmonth[tpmul]<<"/"<<myear[tpmul]<<" :-"<<endl;
							cout<<"Time spent in traveling :-"<<endl;
							cout<<travelfdateh[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" hours  "<<travelfdatem[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" minutes"<<endl;
							cout<<"Percent :- "<<percenttravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<"%   Rate:-"<<ratetravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<endl;
							tpmul++;
						}
						if(d+1==ip)
						{
							cout<<endl<<endl;
							cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
							cout<<"Time spent in traveling :-"<<endl;
							cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
							cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
							d++;
						}
					}
					cout<<endl<<endl;
					cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=30-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<mdate[tpmul]<<"/"<<mmonth[tpmul]<<"/"<<myear[tpmul]<<" :-"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" hours  "<<travelfdatem[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percenttravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<"%   Rate:-"<<ratetravelfdate[concat(mdate[tpmul],mmonth[tpmul],myear[tpmul])]<<endl;
						tpmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
			}
		}
		else
		{
			cout<<endl<<endl;
			cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
			cout<<"Time spent in traveling :-"<<endl;
			cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
			cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
		}
	}

	for(d=0;d<ip;d++)
	{
		wrate=workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
		for(c=0;c<n;c++)
        {
            if(city[c].compare(acity)==0)
            {
                if(concat(date[c],month[c],year[c])==concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]]) )
                {
                    evalcity="ahemdabad";
                    break;
                }
            }
            else
            {
                evalcity=city[uniindex[d]];
            }
        }
        citycmp=evalcity.compare(acity);

		if(0<wrate && wrate<=6)
		{

		     if(citycmp==0)
            {
                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=30;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=156;
            }
            else
            {

                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=30;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=126;
            }
		}
		if(6<wrate && wrate<=12)
		{
		    if(citycmp==0)
            {
                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=50;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=260;
            }
            else
            {
                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=50;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=210;
            }
		}
		if(12<wrate && wrate<=24)
		{
		    if(citycmp==0)
            {
                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=100;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=560;
            }
            else
            {
                percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=30;
                rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=126;
            }
		}
	}
	cout<<endl<<"work evaluation"<<endl;
    for(d=0;d<ip;d++)
	{
        if(d+1==ip)
        {
            cout<<endl<<endl;
            cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
            cout<<"Time spent in working :-"<<endl;
            cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
            cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
            break;
        }

	    if((date[uniindex[d]])+1!=date[uniindex[d+1]] && date[uniindex[d]]!=date[uniindex[d+1]])
		{
            if((month[uniindex[d]]==month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
            {

				cout<<endl<<endl;
                cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
                cout<<"Time spent in working :-"<<endl;
                cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
                cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

				muldate=date[uniindex[d+1]]-date[uniindex[d]];
                muln=date[uniindex[d]];
                muln++;
				for(m=0;m<muldate-1;m++)
                {
                   cout<<endl<<endl;
                   cout<<mdate[wpmul]<<"/"<<mmonth[wpmul]<<"/"<<myear[wpmul]<<" :-"<<endl;
                   cout<<"Time spent in working :-"<<endl;
                   cout<<workfdateh[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" hours  "<<workfdatem[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" minutes"<<endl;
                   cout<<"Percent :- "<<percentworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<"%   Rate:-"<<rateworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<endl;
                   wpmul++;
                }
				if(d+1==ip)
				{
					cout<<endl<<endl;
					cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
					d++;
				}
            }
			if(d==ip)
			{
				break;
			}
			if((month[uniindex[d]]!=month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
			{
				if(month[uniindex[d]]==1 || month[uniindex[d]]==3 || month[uniindex[d]]==5 || month[uniindex[d]]==7 || month[uniindex[d]]==8 || month[uniindex[d]]==10 || month[uniindex[d]]==12)
				{
					cout<<endl<<endl;
					cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=31-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<mdate[wpmul]<<"/"<<mmonth[wpmul]<<"/"<<myear[wpmul]<<" :-"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" hours  "<<workfdatem[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percentworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<"%   Rate:-"<<rateworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<endl;
						wpmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
				if(month[uniindex[d]]==2 || month[uniindex[d]]==4 || month[uniindex[d]]==6 || month[uniindex[d]]==9 || month[uniindex[d]]==11)
				{
					if(month[uniindex[d]]==2)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

						muldate1=28-date[uniindex[d]];
						muldate2=date[uniindex[d+1]];
						muldate=muldate1+muldate2;
						for(m=0;m<muldate-1;m++)
						{
							cout<<endl<<endl;
							cout<<mdate[wpmul]<<"/"<<mmonth[wpmul]<<"/"<<myear[wpmul]<<" :-"<<endl;
							cout<<"Time spent in working :-"<<endl;
							cout<<workfdateh[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" hours  "<<workfdatem[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" minutes"<<endl;
							cout<<"Percent :- "<<percentworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<"%   Rate:-"<<rateworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<endl;
							wpmul++;
						}
						if(d+1==ip)
						{
							cout<<endl<<endl;
							cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
							cout<<"Time spent in working :-"<<endl;
							cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
							cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
							d++;
						}
					}
					cout<<endl<<endl;
					cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=30-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<mdate[wpmul]<<"/"<<mmonth[wpmul]<<"/"<<myear[wpmul]<<" :-"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" hours  "<<workfdatem[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percentworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<"%   Rate:-"<<rateworkfdate[concat(mdate[wpmul],mmonth[wpmul],myear[wpmul])]<<endl;
						wpmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Percent :- "<<percentworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<"%   Rate:-"<<rateworkfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
			}
		}
		else
		{
			cout<<endl<<endl;
			cout<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
			cout<<"Time spent in working :-"<<endl;
			cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
			cout<<"Percent :- "<<percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<"%   Rate:-"<<ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
		}
	}


    for(d=0;d<ip;d++)
	{
		travelnetperc=percenttravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
		worknetperc=percentworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
		travelnetrate=ratetravelfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
		worknetrate=rateworkfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])];
		if(worknetperc==100)
		{
			totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=worknetrate;
			overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=travelnetrate;
		}
		else if(travelnetperc==100)
		{
			totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=travelnetrate;
			overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=worknetrate;
		}
		else
		{
		totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=travelnetrate+worknetrate;
		overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]=0;
		}
	}

	cout<<endl<<"total evaluation"<<endl;

	for(d=0;d<ip;d++)
	{
	    if(d+1==ip)
        {
            cout<<endl<<endl;
            cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
            cout<<"----------------------------"<<endl;
            cout<<"Time spent in traveling :-"<<endl;
            cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
            cout<<"Time spent in working :-"<<endl;
            cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
            cout<<"Total amount to pay :-"<<endl;
            cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
            cout<<"Overtime payment :-"<<endl;
            cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
            cout<<"Net amount to pay"<<endl;
            cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
            break;
        }
	    if((date[uniindex[d]])+1!=date[uniindex[d+1]] && date[uniindex[d]]!=date[uniindex[d+1]])
		{
            if((month[uniindex[d]]==month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
            {

				cout<<endl<<endl;
				cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
				cout<<"----------------------------"<<endl;
				cout<<"Time spent in traveling :-"<<endl;
				cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
				cout<<"Time spent in working :-"<<endl;
				cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
				cout<<"Total amount to pay :-"<<endl;
				cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
				cout<<"Overtime payment :-"<<endl;
				cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
				cout<<"Net amount to pay"<<endl;
				cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

				muldate=date[uniindex[d+1]]-date[uniindex[d]];
                muln=date[uniindex[d]];
                muln++;
				for(m=0;m<muldate-1;m++)
                {
					cout<<endl<<endl;
					cout<<"       "<<mdate[tepmul]<<"/"<<mmonth[tepmul]<<"/"<<myear[tepmul]<<" :-"<<endl;
					cout<<"----------------------------"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<travelfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<workfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
					cout<<"Total amount to pay :-"<<endl;
					cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
					cout<<"Overtime payment :-"<<endl;
					cout<<overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
					cout<<"Net amount to pay"<<endl;
					cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]+overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
					tepmul++;
				}
				if(d+1==ip)
				{
					cout<<endl<<endl;
					cout<<"       "<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
					cout<<"----------------------------"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
					cout<<"Total amount to pay :-"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
					cout<<"Overtime payment :-"<<endl;
					cout<<overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
					cout<<"Net amount to pay"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]+overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
					d++;
				}
            }
			if(d==ip)
			{
				break;
			}
			if((month[uniindex[d]]!=month[uniindex[d+1]]) && (year[uniindex[d]]==year[uniindex[d+1]]))
			{
				if(month[uniindex[d]]==1 || month[uniindex[d]]==3 || month[uniindex[d]]==5 || month[uniindex[d]]==7 || month[uniindex[d]]==8 || month[uniindex[d]]==10 || month[uniindex[d]]==12)
				{
					cout<<endl<<endl;
					cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"----------------------------"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Total amount to pay :-"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
					cout<<"Overtime payment :-"<<endl;
					cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
					cout<<"Net amount to pay"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=31-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<"       "<<mdate[tepmul]<<"/"<<mmonth[tepmul]<<"/"<<myear[tepmul]<<" :-"<<endl;
						cout<<"----------------------------"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<travelfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<workfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
						cout<<"Total amount to pay :-"<<endl;
						cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						cout<<"Overtime payment :-"<<endl;
						cout<<overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						cout<<"Net amount to pay"<<endl;
						cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]+overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						tepmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<"       "<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"----------------------------"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Total amount to pay :-"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						cout<<"Overtime payment :-"<<endl;
						cout<<overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						cout<<"Net amount to pay"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]+overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
				if(month[uniindex[d]]==2 || month[uniindex[d]]==4 || month[uniindex[d]]==6 || month[uniindex[d]]==9 || month[uniindex[d]]==11)
				{
					if(month[uniindex[d]]==2)
					{
						cout<<endl<<endl;
						cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
						cout<<"----------------------------"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
						cout<<"Total amount to pay :-"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
						cout<<"Overtime payment :-"<<endl;
						cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
						cout<<"Net amount to pay"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

						muldate1=28-date[uniindex[d]];
						muldate2=date[uniindex[d+1]];
						muldate=muldate1+muldate2;
						for(m=0;m<muldate-1;m++)
						{
							cout<<endl<<endl;
							cout<<"       "<<mdate[tepmul]<<"/"<<mmonth[tepmul]<<"/"<<myear[tepmul]<<" :-"<<endl;
							cout<<"----------------------------"<<endl;
							cout<<"Time spent in traveling :-"<<endl;
							cout<<travelfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<travelfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
							cout<<"Time spent in working :-"<<endl;
							cout<<workfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<workfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
							cout<<"Total amount to pay :-"<<endl;
							cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
							cout<<"Overtime payment :-"<<endl;
							cout<<overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
							cout<<"Net amount to pay"<<endl;
							cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]+overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
							tepmul++;
						}
						if(d+1==ip)
						{
							cout<<endl<<endl;
							cout<<"       "<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
							cout<<"----------------------------"<<endl;
							cout<<"Time spent in traveling :-"<<endl;
							cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
							cout<<"Time spent in working :-"<<endl;
							cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
							cout<<"Total amount to pay :-"<<endl;
							cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
							cout<<"Overtime payment :-"<<endl;
							cout<<overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
							cout<<"Net amount to pay"<<endl;
							cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]+overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
							d++;
						}
					}
					cout<<endl<<endl;
					cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
					cout<<"----------------------------"<<endl;
					cout<<"Time spent in traveling :-"<<endl;
					cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Time spent in working :-"<<endl;
					cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
					cout<<"Total amount to pay :-"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
					cout<<"Overtime payment :-"<<endl;
					cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
					cout<<"Net amount to pay"<<endl;
					cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;

					muldate1=30-date[uniindex[d]];
					muldate2=date[uniindex[d+1]];
					muldate=muldate1+muldate2;
					for(m=0;m<muldate-1;m++)
					{
						cout<<endl<<endl;
						cout<<"       "<<mdate[tepmul]<<"/"<<mmonth[tepmul]<<"/"<<myear[tepmul]<<" :-"<<endl;
						cout<<"----------------------------"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<travelfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" hours  "<<workfdatem[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<" minutes"<<endl;
						cout<<"Total amount to pay :-"<<endl;
						cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						cout<<"Overtime payment :-"<<endl;
						cout<<overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						cout<<"Net amount to pay"<<endl;
						cout<<totalamountfdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]+overtimefdate[concat(mdate[tepmul],mmonth[tepmul],myear[tepmul])]<<endl;
						tepmul++;
					}
					if(d+1==ip)
					{
						cout<<endl<<endl;
						cout<<"       "<<date[uniindex[d+1]]<<"/"<<month[uniindex[d+1]]<<"/"<<year[uniindex[d+1]]<<" :-"<<endl;
						cout<<"----------------------------"<<endl;
						cout<<"Time spent in traveling :-"<<endl;
						cout<<travelfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Time spent in working :-"<<endl;
						cout<<workfdateh[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" hours  "<<workfdatem[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<" minutes"<<endl;
						cout<<"Total amount to pay :-"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						cout<<"Overtime payment :-"<<endl;
						cout<<overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						cout<<"Net amount to pay"<<endl;
						cout<<totalamountfdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]+overtimefdate[concat(date[uniindex[d+1]],month[uniindex[d+1]],year[uniindex[d+1]])]<<endl;
						d++;
					}
				}
			}
		}
		else
		{
			cout<<endl<<endl;
			cout<<"       "<<date[uniindex[d]]<<"/"<<month[uniindex[d]]<<"/"<<year[uniindex[d]]<<" :-"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"Time spent in traveling :-"<<endl;
			cout<<travelfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<travelfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
			cout<<"Time spent in working :-"<<endl;
			cout<<workfdateh[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" hours  "<<workfdatem[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<" minutes"<<endl;
			cout<<"Total amount to pay :-"<<endl;
			cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
			cout<<"Overtime payment :-"<<endl;
			cout<<overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
			cout<<"Net amount to pay"<<endl;
			cout<<totalamountfdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]+overtimefdate[concat(date[uniindex[d]],month[uniindex[d]],year[uniindex[d]])]<<endl;
		}
	}
return 0;
}