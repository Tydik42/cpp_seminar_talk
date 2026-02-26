//go:build !linux

package main

func platformName() string {
	return "not-linux"
}
