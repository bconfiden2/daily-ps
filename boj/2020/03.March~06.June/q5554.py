homeToSchool = int(input())
schoolToPC = int(input())
PCToAcademy = int(input())
AcademyToHome = int(input())

sum = homeToSchool + schoolToPC + PCToAcademy + AcademyToHome

print(sum // 60)
print(sum % 60)
