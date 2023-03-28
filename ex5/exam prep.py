import os

def recursive_dependencies(dict, str):
    list = []
    final_list = []
    for k, v in dict.items():
        if k == str:
            for dep in dict[k]:
                list.append(dep)
                list+=recursive_dependencies(dict, dep)
    for item in list:
        if item not in final_list:
            final_list.append(item)
    return final_list



print(recursive_dependencies("makefile.txt", "prog"))