using namespace std;

//максимальный размер множества
#define MAX_SIZE 10
#define MAX_SIZE_EXCEPTION "Maximum size is 10";

#define INTEGER_PERMUTATIONS_GENERATOR_SIZE_EXCEPTION "Invalid size of base multiplicity";

#define INTEGER_PERMUTATIONS_GENERATOR_GET_PERMUTATION_INDEX_EXCEPTION "Invalid size of index in method \"getPermutation\"";

#define PERMUTATIONS_GENERATOR_GET_NUMBER_COMPARE_EXEPTION "Permutation can not be compare. If you items can be compare, please create new object of class PermutationsGenerator with COMPARE_FLAG = true. Else you can not call a method \"getNumber\"";
#define PERMUTATIONS_GENERATOR_GET_NUMBER_PERMUTATION_SIZE_EXEPTION "Permutation size is invalid, because this size not equals size of multiplicity. Please, set right size of input permutation and call this method agan. Else you can not call a method \"getNumber\"";