#!/usr/bin/env python
# -*- coding: utf-8 -*-

import csv
import random

def learn(*FILE):
    if not FILE:
        FILE = input("Type the csv filename: ")
    with open(str(FILE), 'r', encoding="utf-8") as f:
        reader = csv.DictReader(f)
        headers = "; ".join([". ".join([str(x[0]).lstrip(" "), x[1].lstrip(" ")]) for x in list(enumerate(reader.fieldnames))])
        give = input("What infos should the program give before asking?\nThe possible options are (please type numbers):\n " + headers + "\n")
        givelist = [reader.fieldnames[int(i)] for i in give.split(" ")]
        askfor = input("What infos should the program ask for?\nThe possible options are (please type numbers):\n " + headers + "\n")
        asklist = [reader.fieldnames[int(i)] for i in askfor.split(" ")]
        notlearned = []
        for row in reader:
            notlearned.append(row)
        while notlearned:
            points = 0
            total = 0
            random.shuffle(notlearned)
            bad = []
            for row in notlearned:
                try:
                    print("; ".join([": ".join([x.lstrip(" "), row[x].lstrip(" ")]) for x in givelist]))
                    for question in asklist:
                        answer = input("  {}? ".format(question.lstrip(" ")))
                        if answer == row[question].lstrip(" "):
                            print("    Good job!")
                            points += 1
                        else:
                            print("    Nope... The answer was: {}".format(row[question].lstrip(" ")))
                            bad.append(row)
                        total += 1
                except Exception as e:
                    print(e)
                    print(row)
            notlearned = bad
            print("{} out of {}!".format(points, total))

        return True
    
if __name__ == "__main__":
    print(learn())
