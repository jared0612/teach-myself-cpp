#ifndef __MEMLEAK__H__
#define __MEMLEAK__H__
#include<string>
#include<unordered_map>

//可以存储内存泄露信息的结构体
struct MemInfo{
    std::string file;
    size_t size;
    size_t line;

};
class MemLeak {
public:
    MemLeak();
    ~MemLeak();
    //通过类方法去调用
    static void setMemInfo(void *p, const char* file, size_t line, size_t size);//将对象分配的信息存储到内存池里面
    static void deleteInfo(void *p);//从内存池里面进行查询，如果有就进行释放
    
private:
    static std::unordered_map<void*, MemInfo> MemPool;
    static MemLeak memleak;

};


void* operator new(size_t size, const char* file, size_t line);
void* operator new[](size_t size, const char* file, size_t line);
void operator delete(void*); 
void operator delete[](void*);

#ifndef _NEW_OVERRIDE_
    #define new new(__FILE__, __LINE__) //后面增加了两个参数
#endif


#endif