#include<iostream>

using namespace std;


/*ѡ����������һ��Ԫ����Ϊ��Ԫ*/
void Quicksort1(int *a,int p,int r)      //Ҫ��r>p                
{
	if (p < r)                                                                     //��Ҫ������Ӧ���жϣ���Ȼ������ѭ����ȥ
	{
		int i = p - 1;
		int j = p;
		for (; j < r ; ++j)                                                         //�����ַ����У�����Ҫ����Ԫ���бȽ�
		{
			cout << p << "    " << r << "    " << j <<"  "<<i<< endl;
			if (a[j] > a[r] || a[j] == a[r])                                        //������Ĵ��ںŸ�ΪС�ںţ����γɵ������ǵ�������
			{
				i++;
				swap(a[i], a[j]);
			}
		}
		cout << i << endl;
		swap(a[++i], a[r]);                               //������Ҫ����++i��д����������  i+1 ����Ϊ����Ҫ�� i �ı���ֵ���м� 1��  ,i++����Ϊ��Ҫ�� i �����Ԫ�ؽ��н��� �� ��д����
		cout << "first " << endl;
		cout << a[0] << "    " << a[1] << "    " << a[2] << "    " << a[3] << "    " << a[4] << "    " << a[5] << "    " << a[6] << "    " << a[7] << "    " << a[8] << "   " << a[9] << endl;
		Quicksort1(a, p, i - 1);
		cout << "two " << endl;
		Quicksort1(a, i + 1, r);

		cout << a[0] << "    " << a[1] << "    " << a[2] << "    " << a[3] << "    " << a[4] << "    " << a[5] << "    " << a[6] << "    " << a[7] << "    " << a[8] << "   " << a[9] << endl;
	}
	
}


/*ѡ������ĵ�һ��Ԫ����Ϊ��Ԫ*/

void Quicksort2(int *a, int left, int right)
{
	if (left < right)                                                                     //��Ҫ������Ӧ���жϣ���Ȼ������ѭ����ȥ
	{
		int i = left;
		int j = right;
		int key = a[left];
		int key_k = left;
		while (i < j)
		{
			while (a[j] > key && i<j)
			{
				j--;
			}
			a[i] = a[j];
			key_k = j;
			while (a[i] < key && i < j)
			{
				i++;
			}
			a[j] = a[i];
			key_k = i;

		}
		a[key_k] = key;
		Quicksort2(a, left, key_k - 1);
		Quicksort2(a, key_k + 1, right);
	}
}


/*ѡ������ĵ�һ��Ԫ����Ϊ��Ԫ*/
void quicksort(int *v, int left, int right)
{
	if (left < right)
	{
		int key = v[left];
		int low = left;
		int high = right;
		while (low < high)
		{
			while (low < high && v[high] > key)
			{
				high--;
			}
			v[low] = v[high];
			while (low < high && v[low] < key){
				low++;
			}
			v[high] = v[low];
		}
		v[low] = key;
		quicksort(v, left, low - 1);
		quicksort(v, low + 1, right);
	}
}




//-------------insertion sort-------------------------
template<typename T>
void insertion_sort(T *a, int n)
{
	T tm;
	for (int i = 0; i != n; ++i) {
		tm = a[i];
		int k = i;
		for (; k>0; --k) {
			if (tm >= a[k - 1])
				break;
			a[k] = a[k - 1];
		}
		a[k] = tm;
	}
}
//---------------------------------------------------


//------------------quick sort----------------------
template<typename T>
T median(T *a, int left, int right)
{
	int center = (left + right) / 2;
	T tm;
	if (a[left] > a[center]) {
		tm = a[left];
		a[left] = a[center];
		a[center] = tm;
	}
	if (a[left] > a[right]) {
		tm = a[left];
		a[left] = a[right];
		a[right] = tm;
	}
	if (a[center] > a[right]) {
		tm = a[center];
		a[center] = a[right];
		a[right] = tm;
	}

	tm = a[center];
	a[center] = a[right - 1];
	a[right - 1] = tm;

	return a[right - 1];
}

template<typename T>
void q_sort(T *a, int left, int right)
{
	// ���ʣ��δ��������鳤��̫С��ʹ�ò��������㷨����ʣ�����������
	if (left + 4 <= right) {
		T pivot = median(a, left, right);
		int i = left;
		int j = right - 1;
		while (true) {
			while (a[++i] < a[pivot]);
			while (a[--j] > a[pivot]);
			if (i < j) {
				T tm = a[i];
				a[i] = a[j];
				a[j] = tm;
			}
			else
				break;
		}//while
		T tm = a[i];
		a[i] = a[right - 1];
		a[right - 1] = tm;

		q_sort(a, left, i - 1);
		q_sort(a, i + 1, right);
	}
	else
		insertion_sort(a + left, right - left + 1);
}

template<typename T>
void quicksort(T *a, int n)
{
	q_sort(a, 0, n - 1);
}
//--------------------------------------------------


int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1,0};
	Quicksort1(a, 0, 9);
	//Quicksort2(a, 0, 9);
	//quicksort(a, 0, 9);
	//quicksort<int>(a, 9);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl;
	system("pause");
	return 0;
}