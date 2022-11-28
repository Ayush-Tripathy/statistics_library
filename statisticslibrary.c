/***
 * 1ST SEMESTER PROJECT
 * Title : Statistics Library
 * Course : Programming in C
 * Faculty: Prof. Chandan Misra
 * Group Number : 10
 * Group Members :
 *      1. Ayush Tripathy (UCSE22011)
 *      2. R Pawan Kumar Reddy (UCSE22027)
 *      3. Subhasis Panda (UCSE22041)
 *      4. Bismay Sarangi (UCSE22048)
 *      5. Tejash Maru (UCSE22049)
 *      6. Aryan Raj (UCSE22059)
 * School : School of Computer Science and Engineering
 * University : XIM University
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// statisticslibary header-file
#include "statisticslibary.h"

// driver function
void main()
{
    int choice, size_u, size_g;
    double num_f;
    
    // menu
    printf("Enter\n");
    printf("1 - Ungrouped Data\n");
    printf("2 - Grouped Data\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\nUngrouped Data \n");
        
        // input for ungrouped data
        printf("Enter size of array: ");
        scanf("%d", &size_u);
        double arr[size_u];
        printf("Enter the numbers: \n");
        for (int i = 0; i < size_u; i++)
        {
            scanf("%lf", &arr[i]);
        }
        
        // output for ungrouped data
        printf("Mean: %f\n", ungrouped_mean(arr, size_u));
        printf("Median: %f\n", ungrouped_median(arr, size_u));
        printf("Mode: %f\n", ungrouped_mode(arr, size_u));
        printf("Max: %f\n", max(arr, size_u));
        printf("Min: %f\n", min(arr, size_u));
        printf("Variance (Pupulation): %f\n", variance(arr, size_u, true));
        printf("Standard deviation (Pupulation): %f\n", standard_deviation(arr, size_u, true));
        printf("Variance (Sample): %f\n", variance(arr, size_u, false));
        printf("Standard deviation (Sample): %f\n\n", standard_deviation(arr, size_u, false));

        printf("Enter any number to find frequency: ");
        scanf("%lf", &num_f);
        printf("Frequency of %lf: %d\n", num_f, frequency(num_f, arr, size_u));
    }
    else if (choice == 2)
    {
        printf("\n\nGrouped Data \n");
        
        // input for grouped data
        printf("Enter the no. of classes: ");
        scanf("%d", &size_g);
        group gd[size_g];
        printf("Enter Data as [lowerlimit upperlimit frequency]\n");
        for (int i = 0; i < size_g; i++)
        {
            scanf("%lf %lf %lf", &gd[i].lower_limit, &gd[i].upper_limit, &gd[i].frequency);
        }
        
        // output for grouped data
        printf("Grouped_Mean: %f\n", grouped_mean(gd, size_g));
        printf("Grouped_Median: %f\n", grouped_median(gd, size_g));
        printf("Grouped_Mode: %f\n", grouped_mode(gd, size_g));
    }
    else
    {
        printf("Invalid Choice.\n");
    }
}

double ungrouped_mean(double numbers[], int size)
{
    // variable 'sum' to store the sum of all elements in array
    double sum = 0;

    // Iterate through all elements in array
    for (int index = 0; index < size; index++)
    {
        // add current element to 'sum' variable
        sum += numbers[index];
    }

    // return mean
    return (double)(sum / size);
}

double ungrouped_median(double numbers[], int size)
{
    // sort elements in ascending order
    sort_numbers(numbers, size);

    bool odd = (size % 2 == 0 ? false : true);

    // variable to store median of numbers
    double median;

    int median_index;

    // calculate median if number of elements is odd
    if (odd)
    {
        median_index = (size + 1) / 2;
        median = numbers[median_index - 1];
    }
    // calculate median if number of elements is even
    else
    {
        int m_1 = size / 2;
        int m_2 = (size / 2) + 1;
        median = (numbers[m_1 - 1] + numbers[m_2 - 1]) / 2;
    }
    return median;
}

double ungrouped_mode(double numbers[], int size)
{
    // variable to store mode of numbers
    double mode;

    int count = 0, max_count = 0;

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // Iterate again through all elements to compare number at index 'i' with number at index 'j'
        for (int j = 0; j < size; j++)
        {
            // if same number increment 'count'
            if (numbers[i] == numbers[j])
            {
                count++;
            }
        }
        // check for maximum counts
        if (count > max_count)
        {
            max_count = count;
            mode = numbers[i];
        }
    }

    return mode;
}

void sort_numbers(double array[], int size)
{
    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // Iterate again through all elements to compare number at index 'i' with number at index 'j'
        for (int j = i + 1; j < size; j++)
        {
            // if number at index 'i' is greater than number at index 'j' swap
            if (array[i] > array[j])
            {
                // swap places
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

double max(double numbers[], int size)
{
    // set current max number to number at index 0
    double max = numbers[0];

    // Iterate though all elements
    for (int i = 1; i < size; i++)
    {
        // if current number is greater than max number then set max number to current number
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

double min(double numbers[], int size)
{
    // set current min number to number at index 0
    double min = numbers[0];

    // Iterate though all elements
    for (int i = 1; i < size; i++)
    {
        // if current number is less than min number then set min number to current number
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    return min;
}

int frequency(double num, double numbers[], int size)
{
    int freq = 0;

    // Iterate though all elements
    for (int i = 0; i < size; i++)
    {
        // if current number is equal to 'num' parameter then increment frequency
        if (numbers[i] == num)
        {
            freq++;
        }
    }
    return freq;
}

double variance(double numbers[], int size, bool population)
{
    double variance;

    // calculate mean of numbers
    double mean = ungrouped_mean(numbers, size);

    double new_array[size];

    // copy elemtents of parameter array 'numbers' to new array 'new_array'
    for (int i = 0; i < size; i++)
    {
        new_array[i] = numbers[i];
    }

    double sum = 0;

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // subtract the calculated mean from each element
        new_array[i] -= mean;
        // square each element
        new_array[i] = new_array[i] * new_array[i];
        // add the element to 'sum'
        sum += new_array[i];
    }

    // calculate variance
    if (population)
    {
        variance = sum / size; // for population
    }
    else
    {
        variance = sum / (size - 1); // for sample
    }

    return variance;
}

double standard_deviation(double numbers[], int size, bool population)
{
    // calculate variance (population)
    double var = variance(numbers, size, population);

    // calculate standard deviation
    double sd = sqrt(var);

    return sd;
}

double grouped_mean(group groups[], int size)
{
    double g_mode;

    // array to store class marks
    double class_marks[size];

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // calculate class mark
        double cm = (groups[i].lower_limit + groups[i].upper_limit) / 2;
        // add class mark to array
        class_marks[i] = cm;
    }

    // summation of Xi*Fi
    double XiFi_sum = 0;
    // summation of Fi
    double freq_sum = 0;

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // update Xi*Fi
        XiFi_sum += (groups[i].frequency * class_marks[i]);
        // update Fi
        freq_sum += groups[i].frequency;
    }

    // calculate mean of grouped data
    g_mode = XiFi_sum / freq_sum;

    return g_mode;
}

double grouped_median(group groups[], int size)
{

    double g_median;

    // array to store frequencies
    double freqs[size];

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // add each frequency
        freqs[i] = groups[i].frequency;
    }

    // array to store cumulative frequencies
    double cumulative_freqs[size];

    for (int i = 0; i < size; i++)
    {
        // set first cumulative frequency to frequency of first group
        if (i == 0)
        {
            cumulative_freqs[i] = freqs[i];
        }
        // calculate and set other cumulative frequencies
        else
        {
            cumulative_freqs[i] = cumulative_freqs[i - 1] + freqs[i];
        }
    }

    // total number of observations
    double cf = cumulative_freqs[size - 1];

    // difference between cumulative frequency of median class and frequency of first group
    double min_diff = (cf / 2) - freqs[0];

    //'min_diff' index
    int f_index = 0;

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // calculate difference between cumulative frequency of median class and frequency of each group
        double diff = (cf / 2) - freqs[i];
        // if diff is less than old diff set new diff
        if (diff >= 0 && diff < min_diff)
        {
            min_diff = diff;
            f_index = i;
        }
    }

    // frequency of median class
    double freq = freqs[f_index];
    // median group
    group f_g = groups[f_index];
    // lower limit of median class
    double l_limit = f_g.lower_limit;
    // median class height
    double class_height = f_g.upper_limit - f_g.lower_limit;

    double cf_prev_class;
    // set cumulative frequency of preceding class of median class
    if (f_index >= 1)
    {
        cf_prev_class = cumulative_freqs[f_index - 1];
    }
    else
    {
        cf_prev_class = cumulative_freqs[f_index];
    }

    // calculate median of grouped data
    g_median = l_limit + ((((cf / 2) - cf_prev_class) / freq) * class_height);

    return g_median;
}

double grouped_mode(group groups[], int size)
{
    // variable for mode of grouped data
    double g_mode;

    // find modal class
    int modal_class_index = modal_class(groups, size);

    // lower limit of modal class
    double l_limit = groups[modal_class_index].lower_limit;
    // frequency of modal class
    double freq_m_class = groups[modal_class_index].frequency;
    // frequency of class preceding modal class
    double freq_prev = groups[modal_class_index - 1].frequency;
    // frequency of class succeeding modal class
    double freq_next = groups[modal_class_index + 1].frequency;
    // modal class height
    double class_height = groups[modal_class_index].upper_limit - groups[modal_class_index].lower_limit;

    // calculate mode of grouped data
    g_mode = l_limit + (((freq_m_class - freq_prev) / ((2 * freq_m_class) - freq_prev - freq_next)) * class_height);

    return g_mode;
}

int modal_class(group groups[], int size)
{
    // modal class index
    int m_class_index = 0;
    // maximum frequency
    double max_f = groups[m_class_index].frequency;

    // Iterate through all elements
    for (int i = 0; i < size; i++)
    {
        // if current frequency is greater than max frequency update max frequency
        if (groups[i].frequency > max_f)
        {
            max_f = groups[i].frequency;
            // set index of max frequency class
            m_class_index = i;
        }
    }

    return m_class_index;
}
