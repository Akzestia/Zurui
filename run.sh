#!/bin/bash

process_name="appZurui"

if pidof "appZurui"; then
    echo "The process '$process_name' is already running."
else
    echo "The process '$process_name' is not running. Starting the application..."
    cd build && ./appZurui &
    echo "Application started."
fi
