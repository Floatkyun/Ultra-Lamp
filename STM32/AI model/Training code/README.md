Pytorch学习框架训练得到的模型文件(.pth)转化为onnx格式的模型文件后，模型在尝试使用CUBE.AI进行量化部署的过程中一直报错。   
无奈只能用TensorFlow学习框架重写训练代码，得到tflite格式的模型文件，这时再用CUBE.AI量化部署才成功。