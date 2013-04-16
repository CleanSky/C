#include <stdio.h>
#include <stdlib.h>

void Choose_Sort(int num[], int length);//选择排序
void Insert_Sort(int num[], int length);//插入排序
void Bubble_Sort(int num[], int length);//冒泡排序
void Quick_Sort(int num[],int start, int end);//快速排序
int Partition(int num[], int p, int r);//快速排序的划分
void Shell_Sort(int num[], int length);//希尔排序
void Heap_Sort(int num[], int length);//堆排序
void Heap_Adjust(int num[], int first, int last);//整理堆的算法
void BinaryTree_Sort(int *num, int length, struct BinaryTree* root);//二叉树排序
void Print_BinaryTree(struct BinaryTree* bt);//中序遍历打印二叉树
void Merge_Sort(int num[], int length);//归并排序
void mergesort(int num[], int first, int last, int temp[]);
void merge(int a[], int first, int mid, int last, int temp[]);//合并两个有序序列
void Count_Sort(int num[], int sorted_num[], int length);//计数排序
void Bucket_Sort(int num[], int length);//桶排序
void Base_Sort(int num[], int length);//基数排序

struct  BinaryTree {
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
};

int main()
{
    const int len = 15;
    int numbers[] = {45, 23, 78, 45, 12, 90, 55, 46, 37, 28, 8, 10, 0, 11, 12};
    int sorted_numbers[len];
    int i = 0;
    struct BinaryTree* root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));

    for (i = 0; i < len; i++) {//输出原始的数组数据
        printf("%d  ", numbers[i]);
    }
    printf("\n");

    //Choose_Sort(numbers, len);//选择排序
    //Insert_Sort(numbers, len);//插入排序
    //Bubble_Sort(numbers, len);//冒泡排序
    //Quick_Sort(numbers, 0, len);//快速排序
    //Shell_Sort(numbers, len);//希尔排序
    //Heap_Sort(numbers, len);//堆排序
    //BinaryTree_Sort(numbers, len, root);//二叉树排序
    //free(root);//释放内存
    //printf("\n");
    //Merge_Sort(numbers, len);//归并排序
    //Count_Sort(numbers, sorted_numbers, len);//计数排序
    //Bucket_Sort(numbers, len);//桶排序

    for (i = 0; i < len; i++) {//输出原始的数组数据
        printf("%d  ", numbers[i]);
    }
    printf("\n");

    return 0;
}

//选择排序
//思想：第i次选择出第i小的数据再与num[i]交换位置
void Choose_Sort(int num[], int length) {
    int temp = 0;
    int i = 0, j = 0;

    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", num[i]);
    }

    printf("\n");
}

//插入排序
//思想：第i次将num[i]插入到已经有序的L[1...i-1]序列中
void Insert_Sort(int num[], int length) {
    int i = 0, j = 0;
    int temp = 0;

    for (i = 1; i < length; i++) {
        temp = num[i];
        for (j = i; j > 0; j--) {
            if (temp < num[j - 1]) {
                num[j] = num[j - 1];
            } else {
                break;
            }
        }
        num[j] = temp;
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", num[i]);
    }

    printf("\n");
}

//冒泡排序
//思想：将待排序列看成竖排的气泡，关键字较小的较轻，向上浮。
void Bubble_Sort(int N[], int length) {
    int i = 0, j = 0;
    int temp = 0;

    for (i = 0; i < length; i++) {
        for (j = length; j > i; j--) {
            if (N[j] < N[j - 1]) {
                temp = N[j - 1];
                N[j - 1] = N[j];
                N[j] = temp;
            }
        }
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", N[i]);
    }

    printf("\n");
}

//快速排序
//思想：基准元素，划分，递归
void Quick_Sort(int num[], int p, int r) {
    int q = 0;

    if (p < r) {
        q = Partition(num, p, r);
        Quick_Sort(num, p, q - 1);
        Quick_Sort(num, q + 1, r);
    }
}

//快速排序的划分
int Partition(int num[], int p, int r) {
    int x = num[r];
    int i = p - 1;
    int j = p;
    int temp = 0;

    for (j = p; j < r; j++) {
        if (num[j] < x) {
            i++;
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    temp = num[i + 1];
    num[i + 1] = num[r];
    num[r] = temp;

    return i + 1;
}

//希尔排序
//思想：分组插入排序，缩小增量排序
void Shell_Sort(int num[], int length) {
    int i = 0, j = 0;
    int d = length / 2;
    int temp = 0;

    for (d = length / 2; d > 0; d = d / 2) {
        for (i = d; i < length; i++) {
            temp = num[i];
            j = i - d;

            while (j >= 0 && temp < num[j]) {
                num[j + d] = num[j];
                j = j - d;
            }
            num[j + d] = temp;
        }
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", num[i]);
    }

    printf("\n");
}

//堆排序
//思想：构建大根堆，调整堆
void Heap_Sort(int num[], int length) {
    int i = 0;
    int temp = 0;

    //调整序列的前半部分，调整后第一个元素是序列的最大元素
    for (i = length / 2 - 1; i >= 0; i--) {
        Heap_Adjust(num, i, length);
    }

    //从最后一个元素开始对序列进行调整，不断缩小调整的范围直到第一个元素
    for (i = length - 1; i > 0; i--) {
        //将第一个元素与当前最后一个元素交换
        //保证当前的最后一个位置的元素都是现在这个序列中最大的
        temp = num[0];
        num[0] = num[i];
        num[i] = temp;

        //不断缩小调整heap的范围，每次调整完毕保证第一个元素是当前序列的最大值
        Heap_Adjust(num, 0, i);
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", num[i]);
    }

    printf("\n");
}

//num是待调整的堆数组，i是待调整的数组元素的位置，length是数组的长度
//根据数组num构建大顶堆
void Heap_Adjust(int num[], int i, int length) {
    int child = 0;
    int temp = 0;

    for (temp = num[i]; 2 * i + 1 < length; i = child) {
        child = 2 * i + 1;//子节点的位置=2*父节点位置+1

        //得到子节点中较大的节点
        if (child < length - 1 && num[child + 1] > num[child]) {
            child++;
        }

        //如果较大的子节点大于父节点则将较大的节点上移替换父节点
        if (temp < num[child]) {
            num[i] = num[child];
        } else {//否则退出循环
            break;
        }

        //最后把需要调整的元素放到合适的位置
        num[child] = temp;
    }
}

//二叉树排序
//思想：构造二叉树，中序遍历
void BinaryTree_Sort(int *num, int length, struct BinaryTree* root) {
    int i = 0;

    if (0 == num || 0 == length) {
        printf("Array is null!\n");
        return;
    }

    root->data = num[0];
    root->left = 0;
    root->right = 0;

    struct BinaryTree* temp = 0;

    for (i = 1; i < length; i++) {
        temp = root;
        struct BinaryTree* t = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        t->data = num[i];
        t->left = 0;
        t->right = 0;

        while (temp != 0) {
            if (t->data > temp->data) {
                if (temp->right == 0) {
                    temp->right = t;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                if (temp->left == 0) {
                    temp->left = t;
                    break;
                } else {
                    temp = temp->left;
                }
            }
        }
    }

    Print_BinaryTree(root);

    return;
}

//中序遍历打印二叉树
void Print_BinaryTree(struct BinaryTree* bt) {
    if (bt == 0) {
        return;
    }

    if (bt->left != 0) {
        Print_BinaryTree(bt->left);
    }

    printf("%d  ", bt->data);

    if (bt->right != 0) {
        Print_BinaryTree(bt->right);
    }

    return;
}

//归并排序
//思想：合并有序序列，递归
void Merge_Sort(int num[], int length) {
    int i = 0;
    int *p = (int *)malloc(sizeof(int) * length);

    if (NULL == p) {
        return;
    }

    mergesort(num, 0, length - 1, p);
    free(p);

    for (i = 0; i < length; i++) {
        printf("%d  ", num[i]);
    }

    printf("\n");

    return;
}

void mergesort(int num[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;

        mergesort(num, first, mid, temp);
        mergesort(num, mid + 1, last, temp);
        merge(num, first, mid, last, temp);
    }
}

//合并两个有序序列
void merge(int a[], int first, int mid, int last, int temp[]) {
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= m) {
        temp[k++] = a[i++];
    }

    while (j <= n) {
        temp[k++] = a[j++];
    }

    for (i = 0; i < k; i++) {
        a[first + i] = temp[i];
    }
}

//计数排序
//思想：输入由一个小范围内的整数构成，对每一个输入元素x，确定出小于x的元素个数
void Count_Sort(int num[], int sorted_num[], int length) {
    int *count_num = (int *)malloc(sizeof(int) * length);
    int i = 0;

    //初始化计数数值
    for (i = 0; i < 100; i++) {
        count_num[i] = 0;
    }

    //统计i的次数
    for (i = 0; i < length; i++) {
        count_num[num[i]]++;
    }

    //对所有的计数累加
    for (i = 1; i < 100; i++) {
        count_num[i] += count_num[i - 1];
    }

    //逆向遍历原数组（保证稳定性），根据计数数组中对应的值填充到数组中
    for (i = length; i > 0; i--) {
        sorted_num[count_num[num[i - 1]] - 1] = num[i - 1];
        count_num[num[i - 1]]--;
    }

    for (i = 0; i < length; i++) {
        printf("%d  ", sorted_num[i]);
    }

    printf("\n");

    free(count_num);
}

//桶排序
//思想：输入符合均匀分布，把区间[0,1)划分成n个相同大小的子区间，将n个输入数分布到各个桶中
//先对各个桶内的数进行排序，在按次序把各桶中的元素列出即可
void Bucket_Sort(int num[], int length) {
    ;
}

//基数排序
//思想：最高有效位、最低有效位
void Base_Sort(int num[], int length) {
    ;
}
