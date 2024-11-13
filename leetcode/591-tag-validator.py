class Solution:
    # def isValid(self, code: str) -> bool:
        


    def HTMLElements(gList):
    """
    1. Add all elements in a list
    2. If encountering a element that doesn't have < at the beginning
        # Skip the element
        change the mode
    3. Check if the last element in the list is same as this next one 
    4. Keep doing it till you encounter an element without / 

    if all the elements are over check to see if the original list is empty
    if it is return true
  
    else return the last element in the list (without <>)
    """

    #####
    # Generating list from given string
    myList = []

    gNo = 0
    myNo = 0
    while gNo < len(gList):
        if gList[gNo] == "<":

        # print("entring first")
        # print("myList")
        # for i in myList:
        #   print(i)
        # print()

        myList.append("")
        myList[myNo] = myList[myNo] + gList[gNo]
        while gList[gNo] != ">":
            gNo+=1
            myList[myNo] = myList[myNo] + gList[gNo]
        myNo+=1
        gNo+=1
        # print("Exiting first")
        # print("myList")
        # for i in myList:
        #   print(i)
        # print()

    
        if gNo < len(gList) and gList[gNo] != "<":
        # print("entering second condition")
        # print("myList")
        # for i in myList:
        #   print(i)
        # print()

        myList.append("")
        while gList[gNo] != "<":
            myList[myNo] += gList[gNo]
            gNo +=1
        myNo+=1
      
    # Checking list
    # print("Checking code")
    myNo = 0
    stEl = 0
    laEl = len(myList) -1

    """

    First Approach  

    set output to true
    Find all left and right of root elements

    move left from first root till you encounter an wrong element or reach 0th element 
    reset the furthest correct element to last element corresponding to 0th

    if the furtheset correct is last exit loop
    else set left and right elements to second roots

    continue till you reach the furthest correct
    """

    # # while myNo < len(myList):
    #   # if myList[stEl].strip("<>/") != myList[laEl].strip("<>/"):
    #   #   return myList[stEl].strip("<>/")

    # # print(len(roots))

    # # Finding roots
    # roots = []
    # rNo = 0
    # while myNo < len(myList):
    #   if myList[myNo].strip("<>")[0] == "/":
    #     # roots.append([-1,-1])
    #     # print(myList[myNo])
    #     roots[rNo][1] = myNo
    #     if myList[roots[rNo][1] - 1][0] == "<":
    #       roots[rNo][0] = roots[rNo][1]-1
    #     else:
    #       roots[rNo][0] = roots[rNo][1] -2
      
    #     while myNo < len(myList) and myList[myNo].strip("<>")[0] == "/":
    #       myNo += 1
    #   myNo +=1

    # # Checking roots

    # output = True
    # for root in roots:
    #   if myList[root[0]].strip("<>/") != myList[root[1]].strip("<>/"):
    #     print(myList[root[0]])
    #     # output = myList[root[0]]
      
    # print(roots)

    """
    second approach

    Add each element to one array

    if encountering non <> element skip
    if encountering element with<>and /
        match it with array last elem  
        if it matches pop remove last element
        else return it 

    if loop ends and checking array is empty return True
    """
    checkingArr = []
    # output = True
    for elem in myList:
        if elem[0] == "<" and elem[1] != "/":
        checkingArr.append(elem.strip("<>/"))
        elif elem[0] == "<" and elem[1] == "/":
        if checkingArr[-1] != elem.strip("<>/"):
            return checkingArr[-1]
        else:
            checkingArr.pop()
        else:
        continue
        # if elem[0]+elem[1] == "</":
        # print(elem)


  