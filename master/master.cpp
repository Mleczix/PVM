#include "stdafx.h"


int main()
{
    int masterId, numOfProcesses = 12, numOfFiles = 12, createdProcesses;
    int childrenIds[1];
    const int index = numOfFiles / numOfProcesses;

    if((masterId = pvm_mytid()) < 0) 
        pvm_perror("Error occured: Could not create master PVM process");
    
    printf("Master ID: %d\n", masterId);

    for(int i = 0; i < index; i++) {
        printf("argv[1]: %s, argv[2]: %s\n", std::to_string(i * numOfProcesses).c_str(), std::to_string((i + 1) * numOfProcesses).c_str());
        char buf1[5], buf2[5];

        sprintf(buf1, "%d", i * numOfProcesses);
        sprintf(buf2, "%d", (i + 1) * numOfProcesses);
        
        char *argsv[] = { 
            buf1,
            buf2,
            (char *) 0
        };

        if((createdProcesses = pvm_spawn("slave", argsv, PvmTaskDefault, "", 1, childrenIds)) < 0) 
            pvm_perror("Error occured: Could not create child PVM process");

    }

    pvm_exit();
    return 0;
}