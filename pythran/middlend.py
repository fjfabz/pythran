'''This module turns a python AST into an optimized, pythran compatible ast'''
from passes import RemoveComprehension, RemoveNestedFunctions, RemoveLambdas, NormalizeTuples, NormalizeReturn, NormalizeMethodCalls, NormalizeAttributes, UnshadowParameters, ExpandImports, GatherOMPData, NormalizeException
from passmanager import apply

def refine(node):
    """refine node in place until it matches pythran's expectations"""
    # parse openmp directive
    apply(GatherOMPData,node)

    # sanitize input
    apply(NormalizeException,node)
    apply(NormalizeMethodCalls,node)
    apply(NormalizeAttributes,node)
    apply(NormalizeTuples,node)
    apply(RemoveComprehension, node)
    apply(NormalizeReturn,node)
    apply(RemoveNestedFunctions, node)
    apply(RemoveLambdas, node)
    apply(ExpandImports,node)
    apply(UnshadowParameters,node)

    # some optimizations
