# -*- coding: utf-8 -*-
"""
Created on Tue May 14 23:26:04 2024

@author: hp
"""

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense,Input


epochs=100
batch_size=64
test_rate=0.15

tempdata1_file_path = 'Room Occupancy.csv'
temp_data1 = pd.read_csv(tempdata1_file_path).drop("HumidityRatio",axis=1)
temp_data1.info()
temp_data1=temp_data1.sample(frac=1)
data_X=temp_data1[["Temperature","Humidity","Light","CO2"]]
data_Y=temp_data1[["Occupancy"]]
data_len=len(data_X)
test_len=int(test_rate*data_len)
train_X=data_X[test_len:data_len-1].values
test_X=data_X[0:test_len-1].values
train_Y=data_Y[test_len:data_len-1].values
test_Y=data_Y[0:test_len-1].values

model = tf.keras.models.Sequential([
    tf.keras.layers.Input(shape=(4), name='input'),
    tf.keras.layers.Dense(32, activation=tf.nn.relu),
    tf.keras.layers.Dense(64, activation=tf.nn.relu),
    tf.keras.layers.Dense(16, activation=tf.nn.relu),
    tf.keras.layers.Dense(2, activation=tf.nn.softmax, name='output')
])
model.summary()

keras_dict = {
    'x': train_X,
    'y': train_Y,
    'batch_size': batch_size,
    'epochs': epochs,
    'shuffle': True,
    'validation_data': (test_X, test_Y)
}
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])
model.fit(
    **keras_dict
)



run_model = tf.function(lambda x: model(x))
BATCH_SIZE = 1
INPUT_SIZE = 4

concrete_func = run_model.get_concrete_function(
    tf.TensorSpec([BATCH_SIZE, INPUT_SIZE], model.inputs[0].dtype))

MODEL_DIR = "Room Occupancy"
model.save(MODEL_DIR, save_format="tf", signatures=concrete_func)

converter = tf.lite.TFLiteConverter.from_saved_model(MODEL_DIR)
tflite_model = converter.convert()
with open('Room_Occupancy.tflite', 'wb') as f:
    f.write(tflite_model)