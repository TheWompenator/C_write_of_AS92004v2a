DATA_FILE = "data.json"

function ASINJECT_init()
    AS_link_data(DATA_FILE)
    return 0
end

function ASINJECT_begin_quiz()
    AS_print("Let's begin!")
    return 0
end

function ASINJECT_end_quiz()
    AS_print("That's the end of the quiz!")
    return 0
end