# -*- coding: utf-8 -*-
"""
Created on Sat Nov 16 11:12:55 2019

@author: bengi
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pydot
from sklearn import metrics
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier, BaggingClassifier, AdaBoostClassifier
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from mlxtend.plotting import plot_decision_regions

##  Load data
columns = list(['dx_type','age','sex','localization','label'])
data = pd.read_csv('HAM10000_metadata(UPDATED).csv',names=columns)
age = data['age']
sex = data['sex']
localization = data['localization']

# Use one hot encoding for categorical features
data['dx_type'] = pd.Categorical(data['dx_type'])
data['sex'] = pd.Categorical(data['sex'])
data['localization'] = pd.Categorical(data['localization'])

# Add dummy variable columns
dummies = pd.get_dummies(data['dx_type'], prefix='dx_type')
data = pd.concat([data, dummies],axis=1)
dummies = pd.get_dummies(data['sex'], prefix='sex')
data = pd.concat([data, dummies],axis=1)
dummies = pd.get_dummies(data['localization'], prefix='localization')
data = pd.concat([data, dummies],axis=1)

# Remove categorical features
data.drop(['dx_type'],axis=1, inplace=True)
data.drop(['sex'],axis=1, inplace=True)
data.drop(['localization'],axis=1, inplace=True)

# Get decision labels
labels = np.array(data['label'])
del data['label']
unique_labels = np.unique(labels)
labelNames = list(['0','1','2','3','4','5','6'])
print(np.where(np.isnan(data)))

##  Train Decision Tree model
xTrain, xTest, labelsTrain, labelsTest = train_test_split(data,labels,test_size=0.1,random_state=1)
decTree = DecisionTreeClassifier(criterion="entropy",max_depth=12,min_impurity_decrease=0.01,max_leaf_nodes=6)
decTree.fit(xTrain,labelsTrain)

decTreePredict = decTree.predict(xTest)

errors = np.not_equal(decTreePredict,labelsTest)
nErrors = sum(errors)
print("Accuracy of decision tree is: "+str(100*metrics.accuracy_score(labelsTest,decTreePredict)))

export_graphviz(decTree, out_file='Q2tree.dot', feature_names = data.columns, rounded = True, precision = 1, class_names = labelNames, label = 'all', filled = True)
(graph,) = pydot.graph_from_dot_file('Q2tree.dot')
graph.write_png('Q2tree.png')