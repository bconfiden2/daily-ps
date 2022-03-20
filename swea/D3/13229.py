for tc in range(int(input())):
    dc = {"MO":0,"TU":1,"WE":2,"TH":3,"FR":4,"SA":5,"SU":-1}
    print(f"#{tc+1} {6-dc[input()[:2]]}")