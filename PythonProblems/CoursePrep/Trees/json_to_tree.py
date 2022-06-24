"""
Connvert json into tree format
ß
{
    "file1": {
        "path_to_file": "file1.txt",
        "children": "file2"
    },
    "file2": {
        "path_to_file": "file1.txt",
        "children": "file3,file4"
    },
    "file3": {
        "path_to_file": "a/file3.txt",
        "children": ""
    },
    "file4": {
        "path_to_file": "b/file4.txt",
        "children": ""
    }
}
"""
import json
json_string = """
{
"root": [1, null,
3, 2, 5, null,
null, null, 4]
}
"""

"""
Logic: Given an array, which is pre-order
Push to queue
While loop till two nulls are encountered
    Level is between the nulls
    Pop first element
    Element is null, return
    Element 

"""


class Node(object):
    def __init__(self, name, path_to_file=None):
        self.name = name
        self.path_to_file = path_to_file
        self.children = []

    def add_child(self, obj):
        self.children.append(obj)

    def dump(self, indent=0):
        """dump tree to string"""
        tab = '    '*(indent-1) + ' |- ' if indent > 0 else ''
        print('%s%s' % (tab, self.name))
        for obj in self.children:
            obj.dump(indent + 1)


name2info = json.loads(json_string)


def get_tree(name):
    info = name2info[name]
    root = Node(name, info['path_to_file'])
    for child in info['children'].split(","):
        if child:
            root.add_child(get_tree(child))
    return root


root = get_tree('root')

# get children info
print(root.name, root.children[0].name, root.children[0].children[1].path_to_file)

root.dump()
