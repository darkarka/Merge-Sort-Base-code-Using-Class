#include<iostream>
#include<vector>
#define f(a,n) for(int i=a;i<n;i++)
using namespace std;

class MergeSort{
public:
    // Constructor that takes a vector of intergers
    MergeSort(std::vector<int>& nums) : arr(nums){}

    // Public method to start the sorting process
    void sort(){
        if(arr.empty()) return;
        mergesort(0, arr.size() - 1);
    }

    // Method to print the array 
    void printArray() const{

        for(int it: arr){
            std:: cout << it << " ";
        }
        std:: cout << std:: endl;
    }

private:
    std::vector<int> &arr;

    // Method to merge two halves in sorted order

    void merge(int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<int> L(n1),R(n2);

        f(0,n1){
            L[i] = arr[left + i];
        }
        f(0,n2){
            R[i] = arr[mid + i + 1];
        }

        int i = 0,j = 0,k = left;

        while (i < n1 && j < n2){
            if(L[i] <= R[j])
            {
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
            }
        }

        while(i < n1){
            arr[k++] = L[i++];
        }

        while(j < n2){
            arr[k++] = R[j++];
        }
        
    }

    // Recursive merge sort method 
    void mergesort(int left,int right){
        if(left < right){
            int mid = left + (right - left)/2;
            mergesort(left,mid);
            mergesort(mid + 1,right);
            merge(left,mid,right);
        }
    }


};



int main()
{
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n); //Create the Vector
    std::cout << "Enter the element :\n" ;
    f(0,n){
        std::cin >> arr[i];
    }

    // Call merge sort

    MergeSort sorted(arr);

    std:: cout << "Original array: ";
    sorted.printArray();

    sorted.sort();

    std:: cout << "Sorted array : ";
    sorted.printArray();


    return 0;
}