package main

//go:generate stringer -type=State
type State int

const (
	Idle State = iota
	Running
	Failed
)
