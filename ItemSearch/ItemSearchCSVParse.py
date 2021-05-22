import csv

# parse CSV
reader = csv.DictReader(open("demoCars.csv"))
id = 100
for item in reader:
    # print item
    print("\t::Item({}, \"{}\", {}, {}, {}, {}, {}),".format(id, item["name"], item["mpg"], item["hp"], item["am"], item["wt"], item["qsec"]))
    id += 1
