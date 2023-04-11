1. 首先创建一个github仓库
2， 本地新建一个文件夹，进入文件夹使用git
    - git init初始化仓库
3. 生成本地密钥
    - git ssh-keygen -t rsa -C "xxx@xxx.com"
4. 去到`.ssh/`下找到`id_rsa.pub`.复制里面的公钥，添加到github中
5. 在本地添加远程仓库
    - git remote add name "xx.git"
6. 配置本地提交着信息
    - git config --global user.email "xxx@xxx.com"
    - git config --global user.name "username"
7. 将要提交的文件添加到暂存区，并进行提交
    - git add "file"
    - git commit -m "info" "file"
8. push到远程仓库
    - git push name branch
