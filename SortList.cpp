/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//就是用链表来实现快排和归并排序，在链表当中实现快排在题目当中会超时
//首先默写出归并排序
//
//
//--------------------链表归并排序---------------------------------
	ListNode *mergeSort(ListNode *head){
		if (head == NULL || head -> next == NULL){
			return head;
		}

		ListNode *p1 = head;
		ListNode *p2 = head;
		ListNode *pre = NULL;

		while (p2 != NULL && p2 -> next != NULL){
			pre = p1;
			p1 = p1 -> next;
			p2 = p2 -> next -> next;
		}
		pre -> next = NULL;

		ListNode *left = mergeSort(head);
		ListNode *right = mergeSort(p1);

		return merge(left, right);

	}

	ListNode *merge(ListNode *left, ListNode *right){
		ListNode *head = new ListNode(0);
		ListNode *delNode = head;

		while (left != NULL && right != NULL){
			if (left -> val < right -> val){
				head -> next = left;
				left = left -> next;
			}
			else{
				head -> next = right;
				right = right -> next;
			}
			head = head -> next;
		}

		if (left != NULL){
			head -> next = left;
		}

		if (right != NULL){
			head -> next = right;
		}

		head = delNode -> next;
		delete delNode;
		return head;

	}
//---------------------------------------------------------


//-----------------------数组归并排序----------------------

	void mergeSort(int a[], int left, int right){
		if (left >= right){
			return ;
		}
		int mid = (left - right)/2 + right;

		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, right);
	}

	int c[10];

	void merge(int a[], int left, int mid, int right){
		int beginl = left;
		int beginr = mid + 1;
		int count = left;

		while (beginl <= mid && beginr <= right){
			if (a[beginl] < a[beginr]){
				c[count ++] = a[beginl ++];
			}
			else{
				c[count ++] = a[beginr ++];
			}
		}

		while (beginl <= mid){
			c[count ++] = a[beginl ++];
		}
		while (beginr <= right){
			c[count ++] = a[beginr ++];
		}

	}
//------------------------------------------------------------
//

//---------------------数组快速排序--------------------------

	void quickSort(int a[], int begin, int end){
		if (begin >= end){
			return ;
		}

		int tmp = a[begin];
		int i = begin;
		int j = end;

		while (i < j){
			while ((i < j) && a[j] > tmp){
				 j --;
			}
			if (j > i){
				a[i] = a[j];
			}

			while ((i < j) && a[i] < tmp){
				i ++;
			}
			if (i < j){
				a[j] = a[i];
			}
		}

		a[i] = tmp;

		quickSort(a, begin, i);
		quickSort(a, i + 1, end);
	}
//-----------------------------------------------------------
//
//
//--------------------链表快速排序--------------------------

	ListNode *quickSort(ListNode *head, ListNode *tail){
		if (head == NULL || head -> next == NULL){
			return head;
		}

		ListNode *h1 = head -> next;
		ListNode *h2 = head -> next;
		ListNode *pre = head -> next;
		int tmp = head -> val;

		while (h2 != NULL && h2 != tail -> next){
			if (h2 -> val < tmp ){
				int swapVal = h1 -> val;
				h1 -> val = h2 -> val;
				pre = h1;
				h2 -> val = h1 -> val;
				h1 = h1 -> next;
			}

			h2 = h2 -> next;
		}
		swap(head -> val, pre -> val);
		quickSort(head, pre);
		quickSort(h1, tail);


	}
//-----------------------------------------------------
    ListNode *sortList(ListNode *head) {

		return mergeSort(head);
    }
};
