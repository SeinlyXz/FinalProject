bb = int(input("Berat Badan: "))
tb = int(input("Tinggi Badan: "))

bmi = bb/(tb/100)**2
print("BMI ku adalah: {}".format(round(bmi)))

if bmi < 17:
    print("Makan yang banyak Lu!!!")
elif bmi >=18 and bmi <= 18.5:
    print("Dikit Lagi Normal")
elif bmi >= 18.5 and bmi <= 25:
    print("Normal Mantap")
elif bmi >= 25 and bmi <= 27:
    print("Agak gemuk")
elif bmi >= 27:
    print("Gemuk")


