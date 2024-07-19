
#define INIT_SIZE 10    // 初始动态数组大小
#define INCREASE_SIZE 5 // 动态数组增长大小

#define i32 int32_t

// 有序顺序表结构体
typedef struct SequenceList{
    i32* data; // 动态数组
    int length;     // 当前长度
    int maxSize;    // 最大容量
} SequenceList;

void InitList(SequenceList *L);
int GetLength(SequenceList L);
void IncreaseSize(SequenceList* L);
void ListInsert(SequenceList* L, i32 x);
void ListDelete(SequenceList* L, i32 x);
i32 GetElem(SequenceList L, int i);
void ListMerge(SequenceList L1, SequenceList L2, SequenceList* L3);

