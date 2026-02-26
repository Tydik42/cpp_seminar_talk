package main

import "fmt"

func main() {
	fmt.Printf("[go] target=%s state=%s\n", platformName(), Running.String())
}
