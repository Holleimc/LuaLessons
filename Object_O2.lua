function People(name)
    local self = {}
    local init = function ()
        self.name = name
    end

    self.isMe = function ()
        print(name.." is me")
    end
    init()
    return self
end

-- local p = People("lisi")
-- p:isMe()

function Man(name)
    local self = People(name)

    self.sayHi = function ()
        print("Hello wangwu, my name is "..name)
    end
    return self
end

local m = Man("lisi")
m:sayHi()
m:isMe()