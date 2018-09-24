def pokolenia(people_list):
    people = {}
    for parent, child in people_list:
        if parent not in people.keys():
            people[parent] = {"children": set(), "parents": set()}
        people[parent]["children"].add(child)
        if child not in people.keys():
            people[child] = {"children": set(), "parents": set()}
        people[child]["parents"].add(parent)

    result = []
    for person in people:
        if not people[person]["parents"]:
            result.append([person])
            break

    for generation in result:
        toappend = []
        for person in generation:
            for child in people[person]["children"]:
                toappend.append(child)
        toappend.sort()
        if toappend:
            result.append(toappend)
    result[0] = result[0][0]
    return result


print(pokolenia([["Ula", "Ala"], ["Ola", "Ula"], ["Ela", "Ola"],
                 ["Ela", "Jan"]]))
print(pokolenia([["a", "b"], ["b", "x"], ["a", "d"], ["a", "z"]]))
