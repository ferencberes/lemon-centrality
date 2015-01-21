lemon-centrality
================

Centrality feature for the C++ Lemon Graph Library project

# Introduction

This repository contains the original source files of [LEMON 1.3.1](http://lemon.cs.elte.hu/trac/lemon) with the additional centrality support.
The source of the centrality support can be found in the [centrality folder](/src/lemon-1.3.1/tools/centrality).

Right now only a few centrality measure is supported, along with some other graph statistics:

  * number of inEdges of a vertex
  * number of outEdges of a vertex
  * Beta measure score of a vertex
  * PageRank score of a vertex
  * Salsa measure score of a vertex
  * Loop/real edge ratio of a vertex

Details about some of the mentioned centrality measures can be found in this [paper](http://vigna.di.unimi.it/ftp/papers/AxiomsForCentrality.pdf).

# Usage

There are some scripts in this repository which can help you in running the code.

If you want to build the repository for the first time use:
```batch
./scripts/buildLemonFirstTime.sh
```
This will create a build folder in the project, where you can find the executables later.

After the first build it is enough if you run the following scripts to rebuild the project:
```batch
./scripts/buildLemon.sh
```

The inputs are read from [lemon graph format](http://lemon.cs.elte.hu/pub/tutorial/a00018.html). 
There is an additional [test file](/src/lemon-1.3.1/tools/centrality/digraph.lgf) on which you can run an acceptence tests to ensure that for a given fix input you always get the same results:
```batch
./scripts/runLemonAcceptenceTest.sh
```

Finally there is a prepared [centrality_test](/src/lemon-1.3.1/tools/centrality/centrality_test.cc) for an arbitrary lemon graph format input which you can run from scripts as well:
```batch
./scripts/runLemonTest.sh <your_lgf_input>
```

