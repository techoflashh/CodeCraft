#include <iostream>
#include <cstdlib>

using ProcessId = int;
using std::cin, std::cout, std::endl;

typedef struct Process *ptrNode;

struct Process
{
    Process *previousProcess;
    Process *nextProcess;
    ProcessId id;
};

class Scheduler
{
public:
    ptrNode LinkedList = NULL;

    /*
          adds process with id = pid to the end of the linked list
    */
    Process *add_process(ProcessId pid)
    {
        // code to add_process goes here
        ptrNode temp = (ptrNode)malloc(sizeof(struct Process));
        temp->id = pid;
        if (LinkedList == NULL)
        {
            ptrNode dummy = (ptrNode)malloc(sizeof(struct Process));
            dummy->nextProcess = dummy;
            dummy->previousProcess = dummy;
            LinkedList = dummy;
        }
        temp->nextProcess = LinkedList;
        temp->previousProcess = LinkedList->previousProcess;
        LinkedList->previousProcess->nextProcess = temp;
        LinkedList->previousProcess = temp;
        return temp;
    }

    /*
          deletes process with id == pid
    */
    void delete_process(ProcessId pid)
    {
        // code to delete_process goes here
        ptrNode temp = LinkedList->nextProcess;
        if (temp != LinkedList)
        {
            while (temp->id != pid)
            {
                temp = temp->nextProcess;
                if (temp == LinkedList)
                {
                    break;
                }
            }
            if (temp->id == pid)
            {
                temp->previousProcess->nextProcess = temp->nextProcess;
                temp->nextProcess->previousProcess = temp->previousProcess;
                free(temp);
            }
        }
    }

    /*
          add a process with id == childId after process with id == parentId
    */
    Process *fork(ProcessId process, ProcessId newId)
    {
        // code to fork process goes here
        ptrNode newNode = (ptrNode)malloc(sizeof(struct Process));
        newNode->id = newId;
        ptrNode temp = LinkedList->nextProcess;
        if (temp != LinkedList)
        {
            while (temp->id != process)
            {
                temp = temp->nextProcess;
                if (temp == LinkedList)
                {
                    break;
                }
            }
            if (temp->id == process)
            {
                newNode->nextProcess = temp->nextProcess;
                newNode->previousProcess = temp;
                temp->nextProcess->previousProcess = newNode;
                temp->nextProcess = newNode;
            }
        }
        return newNode;
    }

    void print_schedule()
    {
        // code to print_schedule goes here
        if (LinkedList->nextProcess != LinkedList && LinkedList != NULL)
        {
            ptrNode temp = LinkedList->nextProcess;
            while (temp != LinkedList)
            {
                cout << temp->id << " ";
                temp = temp->nextProcess;
            }
            cout << endl;
        }
    }
};

enum Operations
{
    ADD_PROCESS,
    DELETE_PROCESS,
    FORK,
    PRINT_SCHEDULE,
};

int main()
{
    Scheduler s;
    int n;
    cin >> n;
    while (n--)
    {
        int operationInput;
        cin >> operationInput;

        Operations opId = static_cast<Operations>(operationInput);

        if (opId == ADD_PROCESS)
        {
            ProcessId newPid;
            cin >> newPid;
            s.add_process(newPid);
        }
        else if (opId == DELETE_PROCESS)
        {
            ProcessId toBeDeletedPid;
            cin >> toBeDeletedPid;
            s.delete_process(toBeDeletedPid);
        }
        else if (opId == FORK)
        {
            ProcessId pidToBeForked;
            ProcessId newPid;
            cin >> pidToBeForked;
            cin >> newPid;
            s.fork(pidToBeForked, newPid);
        }
        else if (opId == PRINT_SCHEDULE)
        {
            s.print_schedule();
        }
    }
}