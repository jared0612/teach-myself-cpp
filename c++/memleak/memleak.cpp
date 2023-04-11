#define _NEW_OVERRIDE_//不希望进行展开，
#include"memleak.h"
#include<iostream>

std::unordered_map<void*, MemInfo> MemLeak::MemPool;
MemLeak MemLeak::memleak; //使用静态变量来控制生命周期，加载文件后就会创建静态变量，文件结束会释放静态变量；

MemLeak::MemLeak() {
    std::cout << "Constructor" << std::endl;
}

MemLeak::~MemLeak() {
    std::cout << "****************Leaked Memory Start*********************************" << std::endl;
    for(auto it : MemPool) {
        std::cout << "Adderss in " << it.first
                  << " size is " << it.second.size
                  << " file in " << it.second.file
                  << " line in " << it.second.line
                  << std::endl;
     }
     std::cout << "****************Leaked Memory End*********************************" << std::endl; 

}

void MemLeak::setMemInfo(void *p, const char* file, size_t line, size_t size)
{
    std::cout << "Malloc Addresss [" << p << "] ";
    std::cout << "Size [" << size << "]";
    std::cout << std::endl;
    memleak.MemPool[p].size = size;
    memleak.MemPool[p].file = file;
    memleak.MemPool[p].line = line;
}

void MemLeak::deleteInfo(void *p){
    std::cout<< "Free Address [" << p << "]\n";
    auto info = MemPool.find(p);
    if(info != MemPool.end()) {
            MemPool.erase(info);//删除这一对象
        
    }
}

void* operator new(size_t size, const char* file, size_t line)
{
    if(size == 0) size = 1;
    void* p = malloc(size);
    if(p == nullptr) {
        std::cout << "ERROR MALLOC~" << std::endl;
    } else {
             MemLeak::setMemInfo(p, file, line, size);
     }
     return p;
}

void* operator new[](size_t size, const char* file, size_t line)
{
    if(size == 0) size = 1;
    void* p = malloc(size);
    if(p == nullptr) {
        std::cout << "ERROR MALLOC[]~" << std::endl;
    } else {
        MemLeak::setMemInfo(p, file, line, size);
     }
     return p;
}

void operator delete(void* p)
{
    MemLeak::deleteInfo(p);
    if(p) free(p);
}

void operator delete[](void* p)
{
    MemLeak::deleteInfo(p);
    if(p) free(p);
}

