#include <iostream>
#include "File.h"
#include "Assembler.h"
#include "Operation.h"
#include "Repo.h"

int main() {
    Repo<int> repo;
    Operation<int>::repo_ = &repo;
    File file;
    file.readDataFromFile<int>("CMakeFiles/data/input.txt", repo);
    Assembler assembler;
    assembler.compileCodeFromFile("CMakeFiles/data/input.txt", repo);
    repo.codeExecute();
    file.outputToJson("CMakeFiles/data/output.json", repo);
    return 0;
}
