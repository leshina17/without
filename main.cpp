#include <iostream>
#include <vector>

//рита - правильно
void merge(int* arr, int left, int mid, int right);
void merge_sort(int* arr, int left, int right){
    if (left<right){
    int mid=(right-left)/2 +left;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
    }

}

void merge(int* arr, int left, int mid, int right){
    size_t s1=mid-left+1;
    size_t s2= right - mid;

    int* left_array = new int[s1];
    int* right_array = new int[s2];

    for (size_t i=0; i<s1; i++){
        left_array[i]=arr[i+left];
    }

    for (size_t i=0; i<s2; i++){
        right_array[i]=arr[i+mid+1];
    }

    size_t i=0,j=0, k=left;

    while (i<s1 && j<s2){
        if (left_array[i]<=right_array[j]){
            arr[k]=left_array[i];
            i++;
        }
        else {
            arr[k]=right_array[j];
            j++;
        }
        k++;
    }

    while (i<s1){
        arr[k]=left_array[i];
        i++;
        k++;
    }

    while (j<s2){
        arr[k]=right_array[j];
        j++;
        k++;
    }

    delete[] left_array;
    delete[] right_array;
}

int main(){

    int arr[6]={2, 3, 8, 9, 17, 0};
    merge_sort(arr,0,5);
    for (size_t i=0; i<6; i++){
        std::cout << arr[i] << std::endl;
    }

    

    return 0;
}

// сортировка слиянием - хорошая сортировка


/*// Функция для слияния двух подмассивов
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Определяем размеры подмассивов
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    // Создаем временные массивы
    std::vector<int> L(n1); 
    std::vector<int> R(n2); 
    // Копируем данные в временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Индексы для первого и второго подмассивов
    int i = 0; // для L[]
    int j = 0; // для R[]
    int k = left; // Индекс для объединенного массива

    // Слияние временных массивов обратно в arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Основная функция сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Находим середину массива
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем первую и вторую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

// Функция для вывода массива на экран
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

// Главная функция
int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    std::cout << "Исходный массив: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
} */


/* быстрая сортировка
8 1 3 7 11 4 18 -1 20 0
pivot = size array/2 (такой элемент берется. то, что меньше перебрасывается влево от этого элемента, то, что больше - вправо)
left = 0;
right = 9;
now - 0 1 3 7 11 4 18 -1 20 8 (поменяли местами 1 и 10)
так делаем до середины, потом делим массив на две части и снова выбираем опорный элемент и перебрасываем элементы между собой
рита прислала фотку кода на следующей паре перенесем это


*/






/*
12 05 2025

bool list_hash_table :: is full(){
bool result = false;
try {
tab_record* a = new tab_record();
delete a;
}
catch (const char*){res = true;}
return res;
}

bool list_hash_table::go_next(){
if (!is_tab_ended()){
bool flag = false;
while (_lists[_curlist].empty()){
_curlist ++;
}
_curelem ++;
if (_curelem==_list[_curlist].end()){
_curlist++;
_curelem = _lists[_curlist].begin();
flag = true;
}
}
return is_table_ended();

}

Key list_hash_table:: get_key() const{ //pdatvalue list_hash_table::getvalue() const {тоже самое что и в этом только в конце get_data;}
return (*_curelem)->get_key();


}   
не факт что так
*/

/*  19.05.25
using PTreeNode = TreeNode*;

class tree_node: public dtabrecord{
protected: 
PTreeNode _pleft;
PTreeNode _pright;

public:
TreeNode(Key key = "", pdatavalue data = nullptr, PTreenode pright = nullptr, PTreeNode pleft = nullptr){
_pleft = pleft;
_pright = pright;
}

PTreeNode const getleft(){
return _pleft;}

PTreeNode const getright(){
return _pright;}

friend class TreeTable;
friend BalancedTreeTable;

virtual PDatValue getcopy(){
PTreeNode copyTree = new TreNode (_key, _data);
return copyTree;
}

}

другой файл stack 
class treetable: public table{
protested: 
PTreeNode _proot;
PTreeNode _pcur;
PTreeNode *_ppref; адрес вершины дерева 
std::stack<PTreeNode> _stack;
size_t _curPOos;
void PrintTreeTable(std::ostream &OS, PTreeNode pNode);
void DrawTreeTable(PTreeNode pNode, size_t lvl);
void DeleteTreeTable(PTreeNode pNode);

public:
TreeTable():Table(){
_proot = nullptr;
_pcur = nullptr;
_ppref = nullptr;
_curpos = 0;}
};
*/