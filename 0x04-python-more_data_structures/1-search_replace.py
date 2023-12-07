#!/usr/bin/python3
def search_replace(my_list, search, replace):
    return [replace if search == b else b for b in my_list]
