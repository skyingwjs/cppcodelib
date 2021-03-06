#include "sort.h"

/*********************************************************************************************
打印输出数组
**********************************************************************************************/
void print(int *pData,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d  ",pData[i]);	
	}
}

/*********************************************************************************************
交换两个数 传指针或引用才能完成实际的交换
**********************************************************************************************/
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void swap1(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
/*********************************************************************************************
交换两个数 不用第三个变量
**********************************************************************************************/

void swap2(int &a, int &b)
{
	if(a!=b){//当a b相等时 没有这句会使得a==0
		a=a^b;
		b=b^a;
		a=a^b;
	}
}
/*********************************************************************************************
冒泡排序的多种实现方法：
冒泡排序是非常容易理解和实现，以从小到大排序举例：
设数组长度为N。
1．比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
2．这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
3．N=N-1，如果N不为0就重复前面二步，否则排序完成。
**********************************************************************************************/


/*********************************************************************************************
冒泡排序1
**********************************************************************************************/
void bubblesort1(int a[],int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=1;j<n-i;j++){
			if(a[j-1]>a[j]){
				swap(&a[j-1],&a[j]);
			}
		} 
}

/*********************************************************************************************
冒泡排序2  对冒泡排序1进行优化，设置一个标志，如果这一趟发生了交换，则为true，否则为false。
明显如果有一趟没有发生交换，说明排序已经完成。
**********************************************************************************************/
void bubblesort2(int a[],int n){
	int j,k=n;
	bool flag=true;
	while(flag){
		flag=false;
		for(j=1;j<k;j++){
			if(a[j-1]>a[j]){
				swap(&a[j-1],&a[j]);
				flag=true;
			}
		}
		k--;
	}
}


/*********************************************************************************************
冒泡排序3: 如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，那么在
第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了，记录下这位置，
第二次只要从数组头部遍历到这个位置就可以了。
**********************************************************************************************/
void bubblesort3(int a[],int n){

	int j,k;
	int flag=n;
	while(flag>0){
		k=flag;
		flag=0;
		for(j=1;j<k;j++){
			if(a[j-1]>a[j]){
				swap(&a[j-1],&a[j]);
				flag=j;
			}
		}	
	}
}


/*********************************************************************************************
冒泡排序4：指针形式的冒泡排序
**********************************************************************************************/

int *bubblesort4(int *pData,int count)
{
   int i,j;
   int temp;
 
   assert(pData!=NULL);
   for(i=1;i<count;i++)//共有count-1轮循环
     for(j=0;j<count-i;j++)//每轮循环 最大的数都移到 最后一个
       if(pData[j]>pData[j+1])//交换相邻两个元素
        {
          temp=pData[j];
          pData[j]=pData[j+1];
          pData[j+1]=temp;
        }
    return pData;
}

/*********************************************************************************************
直接插入排序(Insertion Sort):的基本思想是：每次将一个待排序的记录，按其关键字大小插入到前面已经
排好序的子序列中的适当位置，直到全部记录插入完成为止。

设数组为a[0…n-1]。
1. 初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1
2. 将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。
3. i++并重复第二步直到i==n-1。排序完成。
**********************************************************************************************/

/*********************************************************************************************
直接插入排序1：按照严格的定义书写代码（由小到大排序）
**********************************************************************************************/
void insertsort1(int a[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		//为a[i]在前面的a[0 ... i-1]找到合适的位置
		for(j=i-1;j>=0;j--){
			if(a[j]<a[i])
				break;
		}
		//若找到一个合适的位置
		if(j!=i-1){
			int temp=a[i];
			//将比a[i]大的数据向后移
			for(k=i-1;k>j;k--){
				a[k+1]=a[k];
			}
			//将a[i]放在正确的位置
			a[k+1]=temp;
		}
	}
}

/*********************************************************************************************
这样的代码太长了，不够清晰。现在进行一下改写，将搜索和数据后移这二个步骤合并。即每次a[i]先和前面
一个数据a[i-1]比较，如果a[i] > a[i-1]说明a[0…i]也是有序的，无须调整。否则就令j=i-1,temp=a[i]。
然后一边将数据a[j]向后移动一边向前搜索，当有数据a[j]<a[i]时停止并将temp放到a[j + 1]处。
直接插入排序2：在直接插入排序1上按上述描述改进的方法
**********************************************************************************************/
void insertsort2(int a[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		if(a[i]<a[i-1]){

			int temp=a[i];
			for(j=i-1;j>=0&&a[j]>temp;j--){
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
	}
}


/*********************************************************************************************
再对将a[j]插入到前面a[0…j-1]的有序区间所用的方法进行改写，用数据交换代替数据后移。如果a[j]前一
个数据a[j-1] > a[j]，就交换a[j]和a[j-1]，再j--直到a[j-1] <= a[j]。这样也可以实现将一个新数据新
并入到有序区间。
直接插入排序3：在直接插入排序2上按上述描述改进的方法
**********************************************************************************************/
void insertsort3(int a[],int n){
	int i,j;
	for(i=1;i<n;i++)
		for(j=i-1;j>=0&&a[j]>a[j+1];j--){
			swap(&a[j],&a[j+1]);
		}
}

/*********************************************************************************************
直接插入排序4:指针形式实现
**********************************************************************************************/

int *insertsort4(int *pData,int count)
{
	int pos;
	int temp;
	int i;
	assert(pData!=NULL);

	for(i=1;i<count;i++)
	{
		temp=pData[i];
		pos=i-1;
		//temp与它之前的每一个数作比较直到找到比temp大的那个数 便停止 
		while(pos>=0 && temp<pData[pos])
		{
			pData[pos+1]=pData[pos];//后移 直到temp插入合适的位置
			pos--;
		}
		pData[pos+1]=temp;//执行插入
	}

	return pData;
}

/*********************************************************************************************
希尔排序的实质就是分组插入排序，该方法又称缩小增量排序，因DL．Shell于1959年提出而得名。
该方法的基本思想是：先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）
分别进行直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，
再对全体元素进行一次直接插入排序。因为 直接插入排序在元素基本有序的情况下（接近最好情况），
效率是很高的，因此希尔排序在时间效率上比前两种方法有较大提高。
**********************************************************************************************/

/*********************************************************************************************
希尔排序1：按照严格按照定义来写的希尔排序
**********************************************************************************************/

void shellsort1(int a[],int n){

	int i,j,gap;

	for(gap=n/2;gap>0;gap/=2){//gap即为步长（每组各个元素的索引间隔）

		for(i=0;i<gap;i++){ //gap即为总的组数 依次对每个组的元素进行插入排序

			//每个组的第0个元素（a[i]）默认为有序区间
			for(j=i+gap;j<n;j+=gap){//从每个组的第一个元素(a[j+gap])开始遍历，进行插入排序

				if(a[j]<a[j-gap]){

					int temp=a[j];  //后一个元素

					int k=j-gap;

					while(k>=0&&a[k]>temp){

						a[k+gap]=a[k];

						k-=gap;
					}

					a[k+gap]=temp;//待排序元素temp插入适当的位置
				}
			}
		}
	}
}

/*********************************************************************************************
很明显，上面的shellsort1代码虽然对直观的理解希尔排序有帮助，但代码量太大了，不够简洁清晰。
因此进行下改进和优化，以第二次排序为例，原来是每次从1A到1E，从2A到2E，可以改成从1B开始，
先和1A比较，然后取2B与2A比较，再取1C与前面自己组内的数据比较…….。这种每次从数组第gap个元素开始，
每个元素与自己组内的数据进行直接插入排序显然也是正确的。
也就是让所有组在一个循环里面完成各自组的排序。
**********************************************************************************************/

/*********************************************************************************************
希尔排序2 :在希尔排序1上按上述进行改进
**********************************************************************************************/

void shellsort2(int a[],int n){

	int j,gap;

	for(gap=n/2;gap>0;gap/=2){
		//从数组第gap个元素开始  第一次循环 a[2]和a[0]比较 第二次循环a[3]和a[1]
		//比较 然后a[4] a[2] a[0]  ,a[5] a[3] a[1]
		for(j=gap;j<n;j++){

			if(a[j]<a[j-gap]){

				int temp=a[j];

				int k=j-gap;

				while(k>=0&&a[k]>temp){
					
					a[k+gap]=a[k];

					k-=gap;
				}

				a[k+gap]=temp;
			}			
		}
	}
}


/*********************************************************************************************
再将直接插入排序部分直接插入排序的三种实现的第三种方法insertsort3来改写
希尔排序3：
**********************************************************************************************/
void shellsort3(int a[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
				swap(&a[j], &a[j + gap]);
}


/*********************************************************************************************
直接选择排序和直接插入排序类似，都将数据分为有序区和无序区，所不同的是直接插入排序是将无序区
的第一个元素直接插入到有序区以形成一个更大的有序区，而直接选择排序是从无序区选一个最小的元素
直接放到有序区的最后。
设数组为a[0…n-1]。
1.      初始时，数组全为无序区为a[0..n-1]。令i=0
2.      在无序区a[i…n-1]中选取一个最小的元素，将其与a[i]交换。交换之后a[0…i]就形成了一个有序区。
3.      i++并重复第二步直到i==n-1。排序完成。
**********************************************************************************************/


/*********************************************************************************************
直接选择排序1：
**********************************************************************************************/

void selectsort1(int a[],int n){

	int i,j,minIndex;
	
	for(i=0;i<n-1;i++){//n-1 和 n都可以
		
		minIndex=i;//最小值索引

		for(j=i+1;j<n;j++){

			if(a[j]<a[minIndex]){

				minIndex=j;//无序区最小值索引
			}
		}

		//swap(&a[i],&a[minIndex]);//这里是a[i]与a[minIndex]交换  4种交换方法都可以
		//swap1(a[i],a[minIndex]);
		swap2(a[i],a[minIndex]);

	}

}

/*********************************************************************************************
直接选择排序2：指针形式实现
**********************************************************************************************/
int *selectsort2(int *pData,int count)
{
	int i,j,temp;

	assert(pData!=NULL);

	for(i=0;i<count-1;i++){
		
		for(j=i+1;j<count;j++)

		  if(pData[i]>pData[j]){ //每轮循环都将最小的数移到最前面

		   temp=pData[i];

		   pData[i]=pData[j];

		   pData[j]=temp;

		   }
	 }

	return pData; 
}




//快速排序  以中间元素为基准
int *quicksort(int *pData,int left,int right)//left  right左右索引
{
 int i,j;
 int temp;
 int middle;
 
 i=left;
 j=right;
 
 middle=pData[(left+right)/2];  //数组中间那个元素  基准
 
 do
 {
   while(pData[i]<middle && i<=right)//从左往右找 直到找打第一个大于等于基准的数停止 该数的位置为i
     i++;
   while(pData[j]>middle && j>=left)//从右往左找 直到找打第一个小于等于基准的数停止 该数的位置为j
     j--;
  
   if(i<=j)//交换位置 使得小于基准的数在它的左边区间  大于基准的数在它的右边区间
   {
     temp=pData[i];
     pData[i]=pData[j];
     pData[j]=temp;
     i++;
     j--;
   }
 }
 while(i<=j);//当i==j时 一次划分结束
 
 if(left<j)
   quicksort(pData,left,j);//递归
 if(i<right)
   quicksort(pData,i,right);

 return pData;
}


//快速排序  以第一个元素为最初的基准
int* quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;    
            if(i < j)   
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1); // 递归调用   
        quick_sort(s, i + 1, r);  
    }  
	return s;
}  

//归并排序
//将有二个有序数列a[first...mid]和a[mid...last]合并。
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
//归并排序 递归
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

//归并排序实现
int *mergeSort(int a[], int n)
{
	int *p=(int *)malloc(n*sizeof(int));
	if (p == NULL)
		return NULL;
	mergesort(a, 0, n - 1, p);
	free(p);
	return a;
}

//插入的元素找到合适的位置并调整好整个堆的顺序
void MinHeapFixup(int a[], int i) //
{
    int j, temp;
       temp = a[i];        //从一个非叶子节点开始 
       j = (i - 1) / 2;      //父结点
       while (j >= 0)
       {
              if (a[j] <= temp)//父节点的值 小于 子节点的值 则不用交换 
                     break;
             
              a[i] = a[j];     //把较大的子结点往下移动,替换它的子结点
              i = j;
              j = (i - 1) / 2;
       }
       a[i] = temp;
}

//在最小堆中加入新的数据nNum
void MinHeapAddNumber(int a[], int n, int nNum)
{
       a[n] = nNum;//最后一个位置加上nNum
       MinHeapFixup(a, n);
}

//  从i节点开始调整,n为节点总数，从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
    int j, temp;
 
       temp = a[i];
       j = 2 * i + 1;
       while (j < n)
       {
              if (j + 1 < n && a[j + 1] < a[j]) //在左右孩子中找最小的
                     j++;
 
              if (a[j] >= temp)
                     break;
 
              a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点
              i = j;
              j = 2 * i + 1;
       }
       a[i] = temp;
}



//在最小堆中删除数
void MinHeapDeleteNumber(int a[], int n)
{
       swap(&a[0], &a[n - 1]);//取出根节点元素（最小值）放在数组最后
       MinHeapFixdown(a, 0, n - 1);//调整堆有序化 最小值到根节点
}

//建立最小堆
void MakeMinHeap(int a[], int n)//堆有序化
{
	int i;
       for ( i = n / 2 - 1; i >= 0; i--)  // 父节点从0到 n/2-1  叶子节点不用进行数据下沉 只有父节点要数据下沉 （重新调整顺序）
              MinHeapFixdown(a, i, n);
}

//堆排序
void MinheapsortTodescendarray(int a[], int n)//堆排序  最小堆 排序后是 递减数组
{
	int i;
       for ( i = n - 1; i >= 1; i--)
       {
              swap(&a[i], &a[0]);
              MinHeapFixdown(a, 0, i);
       }
}

