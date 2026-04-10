#!/usr/bin/env python3
import random
import os

def generate_sensor_data(sensor_id, include_temp=True, include_speed=True):
    states = ['включен', 'выключен']
    temps = [round(random.uniform(20.0, 50.0), 1) for _ in range(10)]
    speeds = [
        (random.randint(0, 1000), 'bit'),
        (random.randint(1, 999), 'Kbit'),
        (random.randint(1, 999), 'Mbit'),
        (random.randint(1, 10), 'Gbit')
    ]
    
    state = random.choice(states)
    temp = random.choice(temps) if include_temp else None
    speed_val, speed_unit = random.choice(speeds) if include_speed else (None, None)
    
    result = f"""    Датчик {sensor_id}:
        Состояние: {state}"""
    
    if include_temp and temp is not None:
        result += f"""
        Температура: {temp}"""
    
    if include_speed and speed_val is not None:
        result += f"""
        Скорость: {speed_val} {speed_unit}/s"""
    
    return result + "\n"

def generate_file(filename, num_sensors=2):
    with open(filename, 'w', encoding='utf-8') as f:
        f.write("// Показания датчиков\n")
        for i in range(1, num_sensors + 1):
            f.write(generate_sensor_data(i))
            f.write("\n")

if __name__ == "__main__":
    for i in range(1, 6):
        generate_file(f"report_{i}.txt")
    
    print("Generated 5 test files: report_1.txt ... report_5.txt")