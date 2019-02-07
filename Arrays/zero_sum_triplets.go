// Given an array of distinct elements. The task is to find triplets in array whose sum is zero.
// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
	"strings"
)

// main Driver
func main() {
	array := takeUserInput()
	printZeroSumTripletsV3(array)
}

// takeUserInput ...
func takeUserInput() []int {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter array of integers: ")
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	strs := strings.Split(input[0:len(input)-1], " ")
	integers := make([]int, len(strs))
	for i, str := range strs {
		integers[i], err = strconv.Atoi(str)
		if err != nil {
			log.Fatal(err)
		}
	}

	return integers
}

// printZeroSumTripletsV3 O(n^2) time, O(1) space
func printZeroSumTripletsV3(array []int) {
	found := false
	n := len(array)

	sort.Ints(array)

	for i := 0; i < n-2; i++ {
		l, r := i+1, n-1
		for l < r {
			sum := array[i] + array[l] + array[r]
			if sum == 0 {
				l++
				r--
				fmt.Println(array[i], array[l], array[r])
				found = true
			} else if sum < 0 {
				l++
			} else {
				r--
			}
		}
	}

	if found == false {
		fmt.Println("No zero sum triplets found")
	}
}

// printZeroSumTripletsV2 O(n^2) time, O(n) space
func printZeroSumTripletsV2(array []int) {
	found := false
	n := len(array)
	for i := 0; i < n-2; i++ {
		m := make(map[int]bool)
		for j := i + 1; j < n-1; j++ {
			k := -(array[i] + array[j])
			if _, exists := m[k]; exists {
				fmt.Println(array[i], array[j], k)
				found = true
			} else {
				m[array[j]] = true
			}
		}
	}

	if found == false {
		fmt.Println("No zero sum triplets found")
	}
}

// printZeroSumTripletsV1 O(n^3) time, O(1) space
func printZeroSumTripletsV1(array []int) {
	found := false
	n := len(array)
	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				if array[i]+array[j]+array[k] == 0 {
					fmt.Println(array[i], array[j], array[k])
					found = true
				}
			}
		}
	}

	if found == false {
		fmt.Println("No zero sum triplets found")
	}
}
