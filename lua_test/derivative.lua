function Derivative (f, delta)
    delta = delta or 1e-4
    return function (x)
        return (f(x + delta) - f(x)) / delta
    end
end

C = Derivative(math.sin)
print(math.cos(5.2), C(5.2))
print(math.cos(10), C(10))

function NewCount()
    local count = 0
    return function ()
        count = count + 1
        return count
    end
end

C1 = NewCount()
print(C1())
print(C1())

C2 = NewCount()
print(C2())
print(C2())