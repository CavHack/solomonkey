#! /usr/bin/env python

import sys
import os
import numpy

__author__ = "Karl Whitford / CEVB / The Venire Labs Inc"
__copyright__ = "Copyright (c) 2018 Venire Labs Inc"
__email__ = "cevb@protonmail.com"

def main():
    if len(sys.argv) != 2 or sys.argv[1] == '-h':
        print "Usage: %s OutputFileName" %sys.argv[0]
        print "Data to be printed for each JobGraph Cycle" + \
            "Written Atmically. Check workload directory."

        sys.exit(-1)

        path = sys.argv[1]

        lines = [line.strip().split('\t') for line in open(path)]

        results = {}

        db_index = set() #solomonDB
        tn_index = set() #threading

        for line in lines:
            if line[0][0] == '#':
                continue
            db_name = line[0]
            db_index.add(db_name)

            dir_name, workload = os.path.split(line[1])
            workload = os.path.splitext(workload)[0]

            num_threads = int(line[2])
            tn_index.add(num_threads)

            throughput = float(line[3])
            if not results.has_key(workload):
                results[workload] = {}
            if not results[workload].has_key(db_name):
                results[workload][db_name] = {}
            if not results[workload][db_name].has_key(num_threads):
                results[workload][db_name][num_threads] = []
            results[workload][db_name][num_threads].append(throughput)


            db_index = sorted(db_index)
            tn_index = sorted(tn_index)

            for wl in sorted(results.keys()):
                out_file = open(os.path.join(dir_name, wl + ".Result"), 'w+')
                #prints header
                line = "#"
                for db in db_index:
                    line += '\t' + db
                    out_file.write(line + '\n')
                    #prints results
                for tn in tn_index:
                    line = str(tn)
                    for db in db_index:
                        data = results[wl][db][tn]
                        line += '\t' + str(numpy.median(numpy.array(data)))

                    out_file.write(line + '\n')

if __name__ = '__main__':
    main()
