lemon-centrality
================

Centrality feature for the C++ Lemon Graph Library project

# Introduction

This repository depends on the [LEMON 1.3.1](http://lemon.cs.elte.hu/trac/lemon) graph library.
The sources of the centrality features can be found in the [centrality folder](/src/cpp).

Right now only a few centrality measure is supported, along with some other graph statistics:

  * number of inEdges of a vertex
  * number of outEdges of a vertex
  * Beta measure score of a vertexé2
  * PageRank score of a vertex
  * Salsa measure score of a vertex
  * Loop/real edge ratio of a vertex

Details about some of the mentioned centrality measures can be found in this [paper](http://vigna.di.unimi.it/ftp/papers/AxiomsForCentrality.pdf).

# Usage

There are some scripts in this repository which can help you in running the code.

First you must install all dependencies of the project:
```batch
./src/scripts/common/install_dependencies.sh
```
This script builds you all downloaded dependency project.


This project uses the [Scons](http://www.scons.org/) build tool. So use the following commands to compile the sources:
```batch
cd src/cpp
scons -j4
```

The inputs are read from [lemon graph format](http://lemon.cs.elte.hu/pub/tutorial/a00018.html). 
There is an additional [test file](/resources/example/digraph.lgf) on which you can run an acceptence tests to ensure that for a given fix input you always get the same results:
```batch
./src/scripts/experiments/runLemonAcceptenceTest.sh
```

Finally there is a prepared [centrality_test](/src/cpp/main/centrality/centrality_test.cc) for an arbitrary lemon graph format input which you can run from scripts as well:
```batch
./src/scripts/experiments/runLemonTest.sh <your_lgf_input>
```

