import streamlit as st

st.set_page_config(page_title = "Актуальность темы")

st.sidebar.success("Актуальность темы")

st.write("# Актуальность темы")

st.markdown(
        """
Изучение MAB (Multi-Armed Bandit) алгоритмов имеет несколько актуальных причин:
1. Оптимальное принятие решений в условиях неопределенности
2. Оптимизация ресурсов
3. Адаптация к динамическим ситуациям
4. Применение машинного обучения
""")

st.write(r"""Исследование алгоритмов многоруких бандитов (Multi-Armed Bandit, MAB) 
является актуальным во многих областях, где необходимо принимать решения на основе 
ограниченной информации, в том числе в экономике, маркетинге, медицине, телекоммуникациях 
и других. 
""")

st.markdown(
        """
Актуальность обусловлена широкой областью применения:
1. Показ рекламы
2. Рекомендательные системы
3. Динамическое ценообразование
4. Испытания новых лекарств
5. Альтернатива А/В-тестам
""")

st.markdown(
        """
## Количество публикации о MAB в области рекомендаций
""")

from PIL import Image
image = Image.open('2.png')
st.image(image)
