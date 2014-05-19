#!/usr/bin/env bash

cd "$(dirname "$0")"
/usr/bin/env python3.4 setup.py build_ext --inplace
