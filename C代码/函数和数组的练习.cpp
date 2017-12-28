#include <iostream>
using namespace std;



//全局变量 

int data[100];
int count=0;
//count记录着有几个数字 
void addToEnd(int value)//插入最后面 
{
	data[count]=value;
	count++;
}

void addToFront(int value)//插入最前面 
{
	int i=count;
	while(i>=1)
	{
		data[i]=data[i-1];//数组元素往后退 
		i--;
	} 
	data[0]=value;//插入第一个数 
	count++;//多插入了一个数 
}


//首先k是数组的下标，i<=count-2的原因就是count-1已经是最后的一个元素了
//然后删除一个元素，就是把元素往前面推，data[i]=data[i+1]，在i时，已经可以把后面那位往前面推了
//count-1后面已经没有元素了
 
void removeIndex(int k)  //删除index为K的数字   
{
	int i;
	for(i=k;i<=count-2;i++)//count-1是数组最后一个元素 
	{					   //k代表的是数组的下标 
		data[i]=data[i+1];
	}  
	count--;
}

void removeValues(int value)//将数组中所有的value中的值都去掉 
{
	int i;
	for(i=0;i<count;i++)
	{
		while(data[i]==value)
			removeIndex(i);
		if(count==0)
			break;
	}
		
} 

int countValue(int value)//输出value在数组有多少个 
{
	int n=0;
	int i;
	for(i=0;i<count;i++)
	{
		if(data[i]==value)
		n++;
		
	}
	return n; 
}

float getAverage()//求平均值 
{
	float sum=0;
	int i;
	for(i=0;i<count;i++)
		sum=sum+data[i];
	if(count==0)
		return 0;
	else
		return sum/count;	
}

//输出众数需要mode变量，记录众数出现的次数需要modeFreq变量 /
int getMode()//求众数
{
	int mode=data[0];
	int modeFreq=countValue(mode);//出现的次数
	int i;
	for(i=0;i<count;i++)
	{
		if(countValue(data[i])>modeFreq) {
			modeFreq=countValue(data[i]);
			mode=data[i];
		}
	} 
	return mode;
}
 
int getMax(int n)//找出最大值 
{
	int max=data[0];
	int i;
	for (i=0;i<n;i++)
	{
		if(data[i]>max)
			max=data[i];
			
	}
	return max;
		
} 

int getMaxIndex(int n)//找出数组最大值的下标 
{
	int max=data[0];
	int maxIndex=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(data[i]>max)
		{
			max=data[i];
			maxIndex=i;
		}
	}
	return maxIndex;
}

/*
* 算法：一共有n个元素，找出最大元素的下标，与数组最后一个元素（n-1）交换 
*        最大值已经在数组的最后，n--； 
*		 用while循环以上，直到剩下一个元素 
*/


void selectionSort()
{
	int n=count;
	while(n>1)
	{
		int i=getMaxIndex(n);
		int temp=data[i];
		data[i]=data[n-1];
		data[n-1]=temp;
		n--;
	}
}

void reverse()//数组元素颠倒 
{
	int i=0;
	int j=count-1;
	while(i<j)
	{
		int temp=data[i];
		data[i]=data[j];
		data[j]=temp;
		i++;
		j--;
	}
}

void sortDesc()//从大到小排列
{
	selectionSort(); 
	reverse(); 
}
 
void showData()
{
	int i;
	for(i=0;i<count;i++)
		cout<<data[i];
	cout<<endl;
}

int main()
{
	addToFront(3);
	addToEnd(3);
	addToEnd(5);
	addToEnd(4);
	addToEnd(10);
	addToFront(8);
	selectionSort(); 
	showData(); 
//	sortDesc();
//	showData();
//	showData();
	return 0;
}
