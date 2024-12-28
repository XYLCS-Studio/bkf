//C++ 11 以上才可编译
//BKF (basic kernel framework)
//BKF 基础内核框架
//Create by XYLCS XIT LosefDevLab
//v1.0.r1.b319

//1.请自行嵌入嵌入式开发环境
//2.应用该内核制作系统时,请注意,需要在main()添加更多的系统运行代码,因为该内核需要外部系统程序操作于内核
//3.请注意,部分代码不是在你的系统程序中添加的,而是在内核中添加的,请注意区分,如果实在不懂,可以看看下面有没有注释提示你添加
//1.Please embed the embedded development environment by yourself
//2.When making a system with this kernel, please note that you need to add more system running code in main(), because the kernel needs external system programs to operate in the kernel
//3.Please note that some code is not added in your system program, but in the kernel, please pay attention to distinguish, if you really don't understand, you can see if there is a comment below to remind you to add

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <utility>
#include <iterator>
#include <functional>
#include <numeric>
#include <memory>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>
#include <limits>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cinttypes>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdarg>
#include <csetjmp>
#include <cstdbool>
#include <ctime>
#include <cmath>
#include <cfloat>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <clocale>
#include <ciso646>
#include <csignal>

using namespace std;

// 需要在 C++11 及以上版本才能编译运行
// Need to be compiled and run in C++11 and above versions
class Process {
public:
    Process() = default;
    Process(int id, string name, int priority) : id(id), name(name), priority(priority) {}
    void run() {
        cout << "[INFO] Process " << name << " is running." << endl;
    }//其作用是:运行进程
    //Its function is to run the process
    void stop() {
        cout << "[INFO] Process " << name << " is stopped." << endl;
    }//其作用是:停止进程
    //Its function is to stop the process
    void setPriority(int priority) {
        this->priority = priority;
    }//其作用是:设置进程的优先级
    //Its function is to set the priority of the process
    int getPriority() {
        return priority;
    }//其作用是:获取进程的优先级
    //Its function is to get the priority of the process
    int getId() {
        return id;
    }//其作用是:获取进程的id
    //Its function is to get the id of the process
    string getName() {
        return name;
    }//其作用是:获取进程的名字
    //Its function is to get the name of the process
//在这里添加更多进程代码...
//Add more process code here...
private:    
    int id;
    string name;
    int priority;
};//其作用是:进程
//Its function is: process

class ProcessManager {
public:
    ProcessManager() = default;
    void addProcess(Process process) {
        processes.push_back(process);
    }//其作用是:添加进程
    void removeProcess(int id) {
        for (auto it = processes.begin(); it != processes.end(); ++it) {
            if (it->getId() == id) {
                processes.erase(it);
                break;
            }
        }
    }//其作用是:删除进程
    void runProcess(int id) {
        for (auto it = processes.begin(); it != processes.end(); ++it) {
            if (it->getId() == id) {
                it->run();
                break;
            }
        }
    }//其作用是:运行进程
    void stopProcess(int id) {
        for (auto it = processes.begin(); it != processes.end(); ++it) {
            if (it->getId() == id) {
                it->stop();
                break;
            }
        }
    }//其作用是:停止进程
    void setPriority(int id, int priority) {
        for (auto it = processes.begin(); it != processes.end(); ++it) {
            if (it->getId() == id) {
                it->setPriority(priority);
                break;
            }
        }
    }//其作用是:设置进程的优先级
    int getPriority(int id) {
        for (auto it = processes.begin(); it != processes.end(); ++it) {
            if (it->getId() == id) {
                return it->getPriority();
            }
        }
        return -1;
    }//其作用是:获取进程的优先级
//在这里添加更多进程管理代码...
//Add more process management code here...
private:
    vector<Process> processes;
};//其作用是:进程保险性管理器
//Its function is: Process Insurance Manager

class Kernel {
public:
    Kernel() = default;
    void run() {
        cout << "[MSG] Kernel is running." << endl;
    }//其作用是:运行系统
    //Its function is to run the system
    void stop() {
        cout << "[MSG] Kernel is stopped." << endl;
    }//其作用是:停止系统
    //Its function is to stop the system
    void addProcess(Process process) {
        processManager.addProcess(process);
    }//其作用是:添加进程
    void removeProcess(int id) {
        processManager.removeProcess(id);
    }//其作用是:删除进程
    void runProcess(int id) {
        processManager.runProcess(id);
    }//其作用是:运行进程
    void stopProcess(int id) {
        processManager.stopProcess(id);
    }//其作用是:停止进程
    void setPriority(int id, int priority) {
        processManager.setPriority(id, priority);
    }//其作用是:设置进程的优先级
    int getPriority(int id) {
        return processManager.getPriority(id);
    }//其作用是:获取进程的优先级
//在这里添加更多系统代码...
//Add more system code here...
private:
    ProcessManager processManager;
};

class Driver {
public:
    Driver() = default;
    void run() {
        cout << "[MSG] Driver is running." << endl;
    }//其作用是:运行驱动
    //Its function is to run the driver
    void stop() {
        cout << "[MSG] Driver is stopped." << endl;
    }//其作用是:停止驱动
    //Its function is to stop the driver
    void addProcess(Process process) {
        processManager.addProcess(process);
    }//其作用是:添加进程
    void removeProcess(int id) {
        processManager.removeProcess(id);
    }//其作用是:删除进程
    void runProcess(int id) {
        processManager.runProcess(id);
    }//其作用是:运行进程
    void stopProcess(int id) {
        processManager.stopProcess(id);
    }//其作用是:停止进程
    void setPriority(int id, int priority) {
        processManager.setPriority(id, priority);
    }//其作用是:设置进程的优先级
    int getPriority(int id) {
        return processManager.getPriority(id);
    }//其作用是:获取进程的优先级
//在这里添加驱动代码...
//Add more driver code here...
private:
    ProcessManager processManager;
};

class RS {
public:
    RS() = default;
    void run() {
        cout << "[MSG] RS is running." << endl;
    }//其作用是:运行RunShell
    //Its function is to run RunShell
    void stop() {
        cout << "[MSG] RS is stopped." << endl;
    }//其作用是:停止RunShell
    //Its function is to stop RunShell
    void addProcess(Process process) {
        processManager.addProcess(process);
    }//其作用是:添加进程
    void removeProcess(int id) {
        processManager.removeProcess(id);
    }//其作用是:删除进程
    void runProcess(int id) {
        processManager.runProcess(id);
    }//其作用是:运行进程
    void stopProcess(int id) {
        processManager.stopProcess(id);
    }//其作用是:停止进程
    void setPriority(int id, int priority) {
        processManager.setPriority(id, priority);
    }//其作用是:设置进程的优先级
    int getPriority(int id) {
        return processManager.getPriority(id);
    }//其作用是:获取进程的优先级
    void runCommand(string command) {
        if (command == "run") {
            run();
        } else if (command == "stop") {
            stop();
        } else if (command == "addProcess") {
            int id;
            string name;
            int priority;
            cout << "[I/O] Please input id, name, priority:" << endl;
            cin >> id >> name >> priority;
            Process process(id, name, priority);
            addProcess(process);
        } else if (command == "removeProcess") {
            int id;
            cout << "[I/O] Please input id:" << endl;
            cin >> id;
            removeProcess(id);
        } else if (command == "runProcess") {
            int id;
            cout << "[I/O] Please input id:" << endl;
            cin >> id;
            runProcess(id);
        } else if (command == "stopProcess") {
            int id;
            cout << "[I/O] Please input id:" << endl;
            cin >> id;
            stopProcess(id);
        } else if (command == "setPriority") {
            int id;
            int priority;
            cout << "[I/O] Please input id, priority:" << endl;
            cin >> id >> priority;
            setPriority(id, priority);
        } else if (command == "getPriority") {
            int id;
            cout << "[I/O] Please input id:" << endl;
            cin >> id;
            cout << "[INFO] Priority: " << getPriority(id) << endl;
        } else if (command == "echo") {
            string text;
            cout << "[I/O] Please input text:" << endl;
            cin >> text;
            cout << "[MSG] " << text << endl;
        } else if (command == "cmp") {
            int a, b;
            cout << "[I/O] Please input a, b:" << endl;
            cin >> a >> b;
            if (a > b) {
                cout << "[INFO] a > b" << endl;
            } else if (a < b) {
                cout << "[INFO] a < b" << endl;
            } else {
                cout << "[INFO] a = b" << endl;
            }
        } else if (command == "exit") {
            exit(0);
        } else if (command == "help") {
            cout << "[INFO] Command list:" << endl;
            cout << "run" << endl;
            cout << "stop" << endl;
            cout << "addProcess" << endl;
            cout << "removeProcess" << endl;
            cout << "runProcess" << endl;
            cout << "stopProcess" << endl;
            cout << "setPriority" << endl;
            cout << "getPriority" << endl;
            cout << "echo" << endl;
            cout << "cmp" << endl;
            cout << "exit" << endl;
            cout << "help" << endl;
        } 
        //在这里添加更多command...
        //Add more command here...
        else {
            cout << "[ERROR] Command not found." << endl;
        }
    }

private:
    ProcessManager processManager;
    vector<string> history;
    int historyIndex = -1;

    string getCommand() {
        string command;
        char ch;
        while (true) {
        //选择历史记录命令、获取命令
        //Select historical record command, get command
            ch = getchar();
            if (ch == '\n') {
                cout << endl;
                break;
            } else if (ch == 27) {
                getchar(); // Skip the [
                switch (getchar()) {
                    case 'A':
                        if (historyIndex > 0) {
                            historyIndex--;
                            command = history[historyIndex];
                            cout << "\rCLI> " << command << string(50, ' ') << "\rCLI> " << command;
                        }
                        break;
                    case 'B':
                        if (historyIndex < history.size() - 1) {
                            historyIndex++;
                            command = history[historyIndex];
                            cout << "\rCLI> " << command << string(50, ' ') << "\rCLI> " << command;
                        } else {
                            historyIndex = history.size();
                            command.clear();
                            cout << "\rCLI> " << string(50, ' ') << "\rCLI> ";
                        }
                        break;
                }
            } else {
                command += ch;
                cout << ch;
            }
        }
        return command;
    }

public:
    void runShell() {
        //将getCommand获取到的命令传递给runCommand
        //Pass the command obtained by getCommand to runCommand
        string command;
        while (true) {
            cout << "CLI> ";
            command = getCommand();
            if (!command.empty()) {
                history.push_back(command);
                historyIndex = history.size();
                runCommand(command);
            }
        }
    }
};

int main() {
    cout << "[MSG]Booting..." << endl;
    Kernel kernel;
    Driver driver;
    kernel.run();
    driver.run();
    //在这里添加更多引导代码...
    //Add more boot code here...
    //^^^Boot 引导程序部分
    RS rs;
    rs.run();
    cout << "[MSG]System is running." << endl;
    //在这里添加更多系统运行时代码...
    //Add more system runtime code here...
    rs.runShell();
    //^^^Shell(User Using Experience Interface) 命令行部分(用户使用体验界面部分)
    return 0;
}//System程序部分(外部操作于内核程序部分)
//System program part (external system program operation in kernel program part)