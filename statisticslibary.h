
/**
 * @struct group
 * @brief group is equivalent to a class in Grouped data set.
 * USAGE: {lower_limit, upper_limit, frequency}
 * @var double lower_limit
 * @var double upper_limit
 * @var double frequency
 */
typedef struct group
{
    double lower_limit, upper_limit, frequency;
} group;

/**
 *  @brief Function sorts a ungrouped data set i.e. {1,2,8,4,9,6}
 *  by using Bubble sort that works by repeatedly swapping the adjacent elements if they are in the wrong order.
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 */
void sort_numbers(double array[], int size);

/**
 *  @brief Calculates the mean of ungrouped data set i.e. {1,2,8,4,9,6}
 *  using direct method - sum of all elements/number of elements
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return double mean
 */
double ungrouped_mean(double numbers[], int size);

/**
 *  @brief Calculates the median of ungrouped data set i.e. {1,2,8,4,9,6}
 *  using direct method -
 *  Step 1. Arrange the given values in ascending order.
 *  Step 2. Find the number of observations in the given set of data. It is denoted by n.
 *  Step 3. If n is odd, the median equals the [(n+1)/2]th observation.
 *  Step 4. If n is even, then the median is given by the mean of (n/2)th observation and [(n/2)+1]th observation.
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return double median
 */
double ungrouped_median(double numbers[], int size);

/**
 *  @brief Calculates the mode of ungrouped data set i.e. {1,2,8,4,9,6}
 *  using direct method - returns the most frequent value in the data set
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return double mode
 */
double ungrouped_mode(double numbers[], int size);

/**
 *  @brief Function returns the maximum value in a ungrouped data set i.e. {1,2,8,4,9,6}
 *  works by iterating through whole array and comparing each value to variable 'max'.
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return double max
 */
double max(double numbers[], int size);

/**
 *  @brief Function returns the minimum value in a ungrouped data set i.e. {1,2,8,4,9,6}
 *  works by iterating through whole array and comparing each value to variable 'min'.
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return double min
 */
double min(double numbers[], int size);

/**
 *  @brief Function returns the frequency(number of occurances) of a number provided in a ungrouped data set i.e. {1,2,8,4,9,6}
 *  works by iterating through whole array and checks for equality to variable 'num' if equal then updates the frequency.
 *  @param double num
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @return int freq
 */
int frequency(double num, double numbers[], int size);

/**
 *  @brief Function to calculate the variance (of population or sample) in a ungrouped data set i.e. {1,2,8,4,9,6}
 *  to calculate variance for sample set population parameter to @code false
 *  Process used -
 *  Step 1: Find the mean
 *  Step 2: Find each score’s deviation from the mean
 *  Step 3: Square each deviation from the mean
 *  Step 4: Find the sum of squares
 *  Step 5: Divide the sum of squares by n – 1 (for sample) or N (for population)
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @param bool population
 *  @return double variance
 */
double variance(double numbers[], int size, bool population);

/**
 *  @brief Function to calculate the standard deviation (of population or sample) in a ungrouped data set i.e. {1,2,8,4,9,6}
 *  to calculate standard_deviation for sample set population parameter to @code false
 *  Process used -
 *  Step 1: Find the variance
 *  Step 2: Take square root of variance
 *  @param double[] numbers : array of numbers
 *  @param int size : size of the numbers array
 *  @param bool population
 *  @return double sd
 */
double standard_deviation(double numbers[], int size, bool population);

/**
 *  @brief Function to calculate the mean of grouped data set
 *  Process used -
 *  Step 1: Create array of class marks [class mark(Xi) = (lower limit + upper limit)/2].
 *  Step 2: Calculate product(XiFi) of class mark(Xi) and frequency(Fi) in each group.
 *  Step 3: Take sum of all products in step 2.
 *  Step 4: Calculate the sum of all frequencies.
 *  Step 5: Median = result in step 3 / result in step 4 [Sum of XiFi/Sum of Fi].
 *  @param group groups : group array
 *  @param int size : size of the group array
 *  @return double g_mode
 */
double grouped_mean(group groups[], int size);

/**
 *  @brief Function to calculate the median of grouped data set
 *  Process used -
 *  Step 1: Create array of frequencies.
 *  Step 2: Calculate and create array of cumulative frequencies.
 *  Step 3: Calculate (cumulative frequency of last group / 2).
 *  Step 4: Chech which group's frequency is closest to result in step 3, this is the median class.
 *  Step 5: Median = l + ((((n / 2) - cf) / f) * h).
 *  l is the lower limit of the median class
 *  n is the number of observations
 *  cf is cumulative frequency of the preceding class
 *  f is the frequency of median class
 *  h is the class heigth
 *  @param group groups : group array
 *  @param int size : size of the group array
 *  @return double g_median
 */
double grouped_median(group groups[], int size);

/**
 *  @brief Function returns the index of modal class (class with highest frequency) of grouped data set
 *  works by comparing the frequency of each class with max frequency
 *  @param group groups : group array
 *  @param int size : size of the group array
 *  @return int m_class_index
 */
int modal_class(group groups[], int size);

/**
 *  @brief Function to calculate the mode of grouped data set
 *  Process used -
 *  Step 1: Find the modal clasa.
 *  Step 2: Mode = l + (((f1 - f0) / ((2 * f1) - f0 - f2)) * h)
 *  l is the lower limit of the modal class
 *  f1 is the frequency of modal class
 *  f0 is the frequency of class preceding the modal class
 *  f2 is the frequency of class succeeding the modal class
 *  h is the modal class height
 *  @param group groups : group array
 *  @param int size : size of the group array
 *  @return double g_mode
 */
double grouped_mode(group groups[], int size);