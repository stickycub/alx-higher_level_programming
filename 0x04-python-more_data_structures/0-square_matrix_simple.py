#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    squared_matrix = []
    for line in matrix:
        squared_matrix.append([d**2 for d in line])
    return squared_matrix
