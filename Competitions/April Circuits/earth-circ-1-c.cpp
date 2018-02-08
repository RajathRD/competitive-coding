#include <bits/stdc++.h>

using namespace std;

struct task
{
	int dur1,change1,dur2,change2,taskno;
};

int sum (const vector<int> &a, const vector<int> &b, const vector<task> &tasks )
{
	long long sum1=0,sum2=0;
	for(unsigned int i=0;i<a.size();i++)
	{
		sum1+=tasks[a[i]-1].dur1;

	}
//	cout<<sum1<<endl;
	for(unsigned int i=0;i<b.size();i++)
	{
		sum2+=tasks[b[i]-1].dur2;
	}
//	cout<<sum2<<endl;
	return sum1>=sum2;
}

int sum(const vector<int> &a, const vector<task> &tasks)
{
	int sum=0;
	for(unsigned int i=0;i<a.size();i++)
	{
		sum+=tasks[a[i]].dur1;
	}
	return sum;
}

int main()
{
	unsigned int N,i;
	vector<task> tasks;
	vector<int> moveFirst,moveSecond;
	int f1=1,f2=1;
	cin>>N;
	vector<bool> visited(N+1,false);
	for(i=1; i<=N; i++ )
	{
		int dur1,change1,dur2,change2;
		cin>>dur1>>change1>>dur2>>change2;
		task temp;
		temp.dur1 = dur1;
		temp.change1 = change1;
		temp.dur2 = dur2;
		temp.change2 = change2;
		temp.taskno = i;
		tasks.push_back(temp);

	}

	for(i=0;i<tasks.size();i++) // DO ALL ZEROES FIRST
	{

	//	cout<<"Considering: "<<tasks[i].change1<<" "<<tasks[i].change2<<endl;
		if(tasks[i].change1 == 0 && tasks[i].change2 != 0)
		{
			visited[i]=true;
			moveFirst.push_back(i);
		}
		else if(tasks[i].change2 == 0 && tasks[i].change1 != 0)
		{
			visited[i]=true;
			moveSecond.push_back(i);
		}
		else if(tasks[i].change1 == 0 && tasks[i].change2 == 0)
		{
			if(tasks[i].dur1<tasks[i].dur2)
				{
					visited[i]=true;
					moveFirst.push_back(i);
				}
			else if(tasks[i].dur1<tasks[i].dur2)
				{
					visited[i]=true;
					moveSecond.push_back(i);
				}
			else
			{
				if(sum( moveFirst, moveSecond, tasks ))
				{
					visited[i]=true;
					moveSecond.push_back(i);
				}
				else
				{
					visited[i]=true;
					moveFirst.push_back(i);
				}
			}
		}
	}

	for(i=0; i<N;i++)
	{
		if(visited[i] == false)
		{
			if( f1*tasks[i].dur1+sum(moveFirst,tasks) <= f2*tasks[i].dur2 ) // F1.DUR1+SUM <= F2.DUR2
			{
				moveFirst.push_back(i);
				visited[i]=true;
				f1 = max(1,min(10, f1+tasks[i].change1 ));
			}
			else if( f2*tasks[i].dur2+sum(moveSecond,tasks) <= f1*tasks[i].dur1 )//F2.DUR2+SUM<=F2.DUR2
			{
				moveSecond.push_back(i);
				visited[i]=true;
				f2 = max(1,min(10, f2+tasks[i].change2 ));
			}
			else // COST1+SUM > COST2 , COST2+SUM > COST3
			{
				if( sum(moveFirst,tasks) < sum(moveSecond,tasks) ) //THEN CHOOSE ACCORDING TO LEAST Duration
				{
					moveFirst.push_back(i);
					visited[i]=true;
					f1 = max(1,min(10, f1+tasks[i].change1 ));
				}
				else if( sum(moveSecond,tasks) < sum(moveFirst,tasks ) )
				{
					moveSecond.push_back(i);
					visited[i]=true;
					f2 = max(1,min(10, f2+tasks[i].change2 ));
				}
				else										// IF BOTH DURATIONS ARE SAME
				{
					if( tasks[i].dur1 < tasks[i].dur2 )
					{
						moveFirst.push_back(i);
						visited[i]=true;
						f1 = max(1,min(10, f1+tasks[i].change1 ));
					}
					else if ( tasks[i].dur2 < tasks[i].dur1)
					{
						moveSecond.push_back(i);
						visited[i]=true;
						f2 = max(1,min(10, f2+tasks[i].change2 ));
					}
					else{
						if( f1 < f2) // CHOOSE LOWER FATIGUE
						{
							moveFirst.push_back(i);
							visited[i]=true;
							f1 = max(1,min(10, f1+tasks[i].change1 ));
						}
						else if( f2 < f1 )// IF BOTH FATIGUES ARE SAME
						{
							moveSecond.push_back(i);
							visited[i]=true;
							f2 = max(1,min(10, f2+tasks[i].change2 ));
						}
						else // CHOOSE ACCORDING TO AMOUNT OF TIME SPENT ALREADY
						{
							if( f1+tasks[i].change1 < f2+tasks[i].change2 )
							{
								moveFirst.push_back(i);
								visited[i]=true;
								f1 = max(1,min(10, f1+tasks[i].change1 ));
							}
							else if(f2+tasks[i].change2 < f1+tasks[i].change1 ) /// IF AMOUNT SPENT IS SAME. MAKE SECOND GUY WORK
							{
								moveSecond.push_back(i);
								visited[i]=true;
								f2 = max(1,min(10, f2+tasks[i].change2 ));
							}
							else
							{
								if(tasks[i].change1 < tasks[i].change2)
								{
									moveFirst.push_back(i);
									visited[i]=true;
									f1 = max(1,min(10, f1+tasks[i].change1 ));
								}
								else
								{
									moveSecond.push_back(i);
									visited[i]=true;
									f2 = max(1,min(10, f2+tasks[i].change2 ));
								}
							}
					}
					}
				}
			}
		}

	}

	if(moveFirst.size() == 0)
		cout<<0<<endl;
	else
		cout<<moveFirst.size()<<"\n";
	for(unsigned int i=0; i<moveFirst.size();i++)
		cout<<moveFirst[i]+1<<" ";
	cout<<endl;
	cout<<moveSecond.size()<<"\n";
	for(unsigned int i=0;i<moveSecond.size();i++)
		cout<<moveSecond[i]+1<<" ";
//	sum(moveFirst,moveSecond, tasks);


}
